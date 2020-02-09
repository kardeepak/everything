#!/usr/bin/env python3

import sys
from collections import defaultdict

class Token:
	def __init__(self, operation, line, position, loop_pair=None):
		self.operation = operation
		self.line = line
		self.position = position
		self.loop_pair = loop_pair

	def __str__(self):
		return self.operation

	def __repr__(self):
		return str(self)

def error(message):
	print(message)
	sys.exit(1)

def parse_arguments():
	if len(sys.argv) == 2:
		return sys.argv[1], None
	if len(sys.argv) == 3:
		return sys.argv[1], sys.argv[2]
	error("Usage: python3 interpreter.py <filename> <input_file>")

def read_file(filename):
	try:
		with open(filename, "r") as file:
			return file.read()
	except:
		error("IO Error : File {} not found.".format(filename))

def parse_source_code(source_code):
	line_no = 1; char_no = 1;
	loop_stack = []
	parsed_tokens = [] 
	commented = False

	for index, character in enumerate(source_code):
		# Handle Single Line Comments
		if character == "#":	commented = True
		if character == "\n":	commented = False
		if commented is True:	continue

		# Ignore anything other than allowed characters
		if character in "+-<>.,":
			parsed_tokens.append(Token(character, line_no, char_no))
		elif character == "[":
			loop_stack.append(len(parsed_tokens))
			parsed_tokens.append(Token(character, line_no, char_no))
		elif character == "]":
			if not loop_stack:
				error("Syntax Error : Unexpected closing bracket at line {line} position {char}".format(line=line_no, char=char_no))

			opening = loop_stack.pop()
			closing = len(parsed_tokens)

			parsed_tokens.append(Token(character, line_no, char_no, loop_pair=opening))
			parsed_tokens[opening].loop_pair = closing

		char_no += 1
		if character == "\n":
			line_no += 1
			char_no = 1

	return parsed_tokens

def execute(tokens, input_data):
	if input_data:
		input_data = list(input_data)
	memory = defaultdict(int)
	pointer = 0
	output = ""

	position = 0
	while position < len(tokens):
		token = tokens[position]
		character = token.operation
		loop_pair = token.loop_pair
		if character == "+":
			memory[pointer] += 1
		elif character == "-":
			memory[pointer] -= 1
		elif character == ">":
			pointer += 1
		elif character == "<":
			pointer -= 1
		elif character == ".":
			output += chr(memory[pointer])
		elif character == ",":
			if not input_data:
				error("Runtime Error : Cannot read from input at line {} position {}".format(token.line, token.position))
			memory[pointer] = ord(input_data.pop(0))
		elif character == "[":
			if memory[pointer] == 0:
				position = loop_pair
		elif character == "]":
			if memory[pointer] != 0:
				position = loop_pair
		position += 1

	return output

def main():
	source_file, input_file = parse_arguments()
	source_code = read_file(source_file)
	input_data = read_file(input_file) if input_file is not None else None
	tokens = parse_source_code(source_code)
	print(execute(tokens, input_data), end="")

if __name__ == '__main__':
	main()