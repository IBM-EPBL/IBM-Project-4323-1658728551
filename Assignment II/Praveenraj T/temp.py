import random

temp = random.randint(1,900)
hum = random.randint(1,900)
if temp > 500:
  print("Threshold Reached")
else:
  print("Threshold Not Reached")
