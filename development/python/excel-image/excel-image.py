#!/usr/bin/env python3
import xlsxwriter
from PIL import Image
import sys

if len(sys.argv) < 2:
	print("Usage : python3 excel-image.py <path to image>")
	quit()

def convert_to_hex(red, green, blue):
	return "#" + "".join(map(lambda x: hex(min(x, 255)).replace("0x", ""), [red, green, blue]))

image = Image.open(sys.argv[1])

width, height = image.size
while width > 128 or height > 128:
	width //= 2
	height //= 2

image = image.resize((width, height), Image.ANTIALIAS)
pixels = image.load()
columns, rows = image.size

workbook = xlsxwriter.Workbook('Image.xlsx')
worksheet = workbook.add_worksheet()

for row in range(rows):
	for column in range(columns):
		print(row, column)
		red, green, blue, _ = pixels[column,row]
		print(pixels[column, row])
		cell_format = workbook.add_format()
		cell_format.set_bg_color(convert_to_hex(red, green, blue))
		worksheet.write_blank(row, column, "", cell_format)


workbook.close()


