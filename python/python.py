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
def see_your_balance(balance, user, u_name, transfer_sum):
    print("To see your balance after bequeath, enter your username:")
    your_username = input("Enter your username: ")

    if user == your_username:
        save_balance_to_file(balance, your_username)
        # Assuming save_balance_to_file is a function you've defined separately
        # Also assuming sum and send functions are defined elsewhere
        print(f"Your updated balance is: {balance}")
        balance_sum = sum(u_name)
        send(u_name, balance_sum, transfer_sum)
        # Assuming menu_balance, system_clear, and main_menu functions are defined elsewhere
        menu_balance(balance_sum, your_username)
        system_clear()
        main_menu()
    else:
        print("Invalid Username")
        see_your_balance(balance, user, u_name, transfer_sum)




#4
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

#5
def main():
    answer = input("If you have an account enter 'login' or if you want to create a new one enter 'create'!\n")
    if answer == "create":
        reg()
    elif answer == "login":
        login()
    else:
        print("Invalid input")

main()


#6
def exc(num):
    try:
        if num != 1 and num != 2:
            raise num
    except int as choose1:
        print("Please enter a number between 1 and 2.")



#7 Function to add money to the account
def addMoney(balance):
    amount = float(input("Enter the amount to add: "))
    balance += amount
    print("Money added successfully. New balance:", balance)

#8

def menuBalance(balance, userName):
    choice = ''
    while choice != '2':
        print("1. Add money")
        print("2. Save balance")
        choice = input("Enter your choice: ")
        if choice == '1':
            addMoney(balance)
        elif choice == '2':
            saveBalanceToFile(balance, userName)
        else:
            print("Invalid choice. Try again.")



#9 Function to save balance to a text file
def save_balance_to_file(balance, user):
    with open(f"{user}.txt", 'w') as file:
        file.write(str(balance))
        print("Balance saved to file.")


#10
def balance_func(user_name):
    balance = 0.0

    # Load previous balance from file (if available)
    try:
        with open(f"{user_name}.txt", 'r') as file:
            balance = float(file.read())
            print(f"Previous balance loaded: {balance}")
    except FileNotFoundError:
        pass

    menu_balance(balance, user_name)

    return balance


#11
def menu(current_balance, user):
    while True:
        print("\nIf you wish to bequeath an asset or liability, choose from the options below:")
        print("1. Asset")
        print("2. Liability")
        choose = input("Enter your choice: ")

        if choose == '1':
            clear_screen()
            asset(current_balance, user)
        elif choose == '2':
            clear_screen()
            liability()
            break
        else:
            exc(choose)

#12
def account(user):
    currentBalance = balanceFunc(user)
    menu(currentBalance, user)




#13
def userExists(username):
    with open("names.txt", "r") as file:
        for line in file:
            if username in line:
                return True
    return False




#14

def check(username, password, userFile, passFile):
    with open(userFile, 'r') as file, open(passFile, 'r') as file1:
        storedUsername = ''
        storedPassword = ''
        for line1, line2 in zip(file, file1):
            storedUsername = line1.strip()
            storedPassword = line2.strip()
            if storedUsername == username:
                return storedPassword == password
    return False

#15
def login():
    user_name = input("\nEnter your username: ")
    password = input("\nEnter your password: ")

    if check(user_name, password, "names.txt", "passwords.txt"):
        clear_screen()

        path = "../../textFiles/acc.txt"
        display_func(path)

        print(f"Hello {user_name},")
        print("This is your bank account!")
        account(user_name)
    else:
        print("\nInvalid username or password. Try again!")
        login()

#16

def main_menu():
    path = "../../textFiles/mainMenu.txt"
    display_func(path)
    answer = input("\nIf you have an account enter 'login' or if you want to create a new one enter 'create'!\nEnter answer: ")

    if answer == "create":
        clear_screen()
        path = "../../textFiles/register.txt"
        display_func(path)
        reg()
    elif answer == "login":
        clear_screen()
        path = "../../textFiles/login.txt"
        display_func(path)
        login()
    else:
        clear_screen()
        print("Invalid input")
        main_menu()






#17 front-end function

def displayFunc(path):
    with open(path, 'r') as newfile:
        if newfile:
            for line in newfile:
                print(line)







