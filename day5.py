# create an empty list called "shopping list"
from decorator import append


shopping_list = []
for _ in range(3):
    item = input("Please enter an item you want to buy: ")
    shopping_list.append(item)
print("Your shopping list is: ", shopping_list)
print("the sum of the items in the shopping list is: ", len(shopping_list))
