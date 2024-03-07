# 4. Write a program to create, append, and remove lists in python.
# List in python
FriendsName = ['Shaid', 'Shuvabrata', 'Vineet', 'Jahid', 'Asif']
PetsName = ['Cat', 'Dog', 'Zebra', 'Elephant', 'Rat']
print(f"All friends name: {FriendsName}")
print(f"And their pets: {PetsName}")
appending = FriendsName + PetsName
print(f"Appending: {appending}")
PetsName.remove('Rat')
print(f"After Removing: {PetsName}")