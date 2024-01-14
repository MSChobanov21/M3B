#1
def sum(userName):
    balance = 0.0
    with open(userName + ".txt", 'r') as file:
        balance = float(file.read())
    return balance


#2
def send(user, balance, transferSum):
    with open(user + ".txt", "w") as file:
        if file:
            balance = balance + transferSum
            file.write(str(balance))
            print("Balance saved to file.")
        else:
            print("Error: Unable to open file for saving balance.")


#3
def asset(balance):
    print("Who do you want to transfer money to?")
    print("Enter username: ")
    uName = input()
    with open("names.txt", "r") as file:
        found = False
        for line in file:
            if uName in line:
                found = True
    if found:
        print("What amount of money do you want to transfer to", uName, "?")
        transferSum = float(input())
        if transferSum <= balance:
            print("Transfer was successful!")
            balance -= transferSum
            print("If you want to see your balance after transfer enter your username:")
            yourUsername = input()
            saveBalanceToFile(balance, yourUsername)
            print("Your updated balance is:", balance)
            balanceSum = sum(uName)
            send(uName, balanceSum, transferSum)
            menu(balance)
        else:
            print("Transfer cancelled, please try again!")
    else:
        print("Invalid Username")

#4
def main():
    answer = input("If you have an account enter 'login' or if you want to create a new one enter 'create'!\n")
    if answer == "create":
        reg()
    elif answer == "login":
        login()
    else:
        print("Invalid input")

main()


#5
def exc(num):
    try:
        if num != 1 and num != 2:
            raise num
    except int as choose1:
        print("Please enter a number between 1 and 2.")



#6
def addMoney(balance):
    amount = float(input("Enter the amount to add: "))
    balance += amount
    print("Money added successfully. New balance:", balance)


#7
def saveBalanceToFile(balance, user):
    with open(user + ".txt", "w") as file:
        file.write(str(balance))
        print("Balance saved to file.")
    else:
        print("Error: Unable to open file for saving balance.")


#8
def balanceFunc(userName):
    balance = 0.0
    with open(userName + ".txt", 'r') as file:
        balance = float(file.readline())
        print("Previous balance loaded:", balance)
    choice = ''
    while choice != '2':
        print("1. Add money")
        print("2. Save balance")
        choice = input("Enter your choice: ")
        if choice == '1':
            balance = addMoney(balance)
        elif choice == '2':
            saveBalanceToFile(balance, userName)
        else:
            print("Invalid choice. Try again.")
    return balance


#9
def menu(currentBalance):
    print()
    print("If you wish to bequeath an asset or liability you can choose from the options below.")
    print("1. Asset")
    print("2. Liability")
    choose = int(input())
    if choose == 1:
        asset(currentBalance)
    elif choose == 2:
        pass
    else:
        exc(choose)


#10
def account(user):
    currentBalance = balanceFunc(user)
    print("Those are your liabilities: ")
    menu(currentBalance)


#11
def login():
    userName = input("Enter Your UserName: ")
    Pass = input("Enter Your password: ")
    if check(userName, Pass, "names.txt", "passwords.txt"):
        print("Hello", userName, ",")
        print("This is your bank account!")
        account(userName)
    else:
        print("Invalid username or password.")



