from selenium import webdriver
import time

def isprime(n):
	if n < 2 or n % 2 == 0:	
		return False
	i = 3
	while i*i <= n:
		if n%i == 0:
			return False
		i += 2
	return True

driver = webdriver.Chrome()

driver.get("https://isthisprime.com/game/")

time.sleep(5)

driver.find_element_by_id("start").click()

number_element = driver.find_element_by_id("n")
yes_element = driver.find_element_by_id("yes")
no_element = driver.find_element_by_id("no")

while number_element.is_displayed():
	value = int(number_element.text)
	if isprime(value):
		yes_element.click()
	else:
		no_element.click()

time.sleep(5)

driver.quit()