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
def asset(balance, user):
    print("Who do you want to bequeath money to?")
    u_name = input("Enter username: ")

    with open("names.txt") as file:
        found = any(u_name in line for line in file)

    if found:
        while True:
            try:
                transfer_sum = float(input(f"What amount of money do you want to bequeath to {u_name}?\nEnter amount: "))
                break
            except ValueError:
                print("Please enter a number!")

        if transfer_sum <= balance:
            print("Bequeath was successful!")
            balance -= transfer_sum
            see_your_balance(balance, user, u_name, transfer_sum)
        else:
            clear_screen()
            print("Bequeath cancelled, please try again!")
            asset(balance, user)
    else:
        print("Invalid Username. Try again!")
        asset(balance, user)

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

def menu_balance(balance, user_name):
    while True:
        print("1. Add money")
        print("2. Save balance")
        print("3. Make will")
        print("4. Logout")
        choice = input("Enter your choice: ")

        if choice == '1':
            clear_screen()
            add_money(balance)
        elif choice == '2':
            clear_screen()
            save_balance_to_file(balance, user_name)
        elif choice == '3':
            clear_screen()
            asset(balance, user_name)
        elif choice == '4':
            clear_screen()
            main_menu()
            break
        else:
            clear_screen()
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
def userExists(username):
    with open("names.txt", "r") as file:
        for line in file:
            if username in line:
                return True
    return False




#12

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

#13
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

#14

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






#15 front-end function

def displayFunc(path):
    with open(path, 'r') as newfile:
        if newfile:
            for line in newfile:
                print(line)



#16
import getpass

def reg():
    print("\n**** Create New Account ****")

    new_name = input("\nEnter new username: ")

    with open("names.txt", 'a') as out:
        out.write(new_name + '\n')

    if user_exists(new_name):
        clear_screen()
        print("Username already exists. Try a different one.")
        reg()
    else:
        print("\nEnter new password: ", end='')
        new_pass = getpass.getpass()

        with open("passwords.txt", 'a') as out1:
            out1.write(new_pass + '\n')

        confirm_pass = getpass.getpass("\nConfirm the password: ")

        if confirm_pass == new_pass:
            print("\n===================================")
            print("\nSuccessfully created a new account!\n")
            print("===================================")
            print("\nIf you want to log in to your account, enter '1':")

        else:
            print("\nPassword confirmation not correct!")

    while True:
        num_log = input()
        if num_log == '1':
            clear_screen()
            path = "../../textFiles/login.txt"
            display_func(path)
            login()
            break
        else:
            print("Wrong input. Try again:")






