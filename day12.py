class BankAccount:
    def __init__(self, account_holder, initial_balance):
        self.account_holder = account_holder
        self.balance = initial_balance

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            print(f"Deposited ${amount}. New balance is ${self.balance}.")
        else:
            print("Deposit amount must be greater than 0.")

    def withdraw(self, amount):
        if 0 < amount <= self.balance:
            self.balance -= amount
            print(f"Withdrew ${amount}. New balance is ${self.balance}.")
        elif amount > self.balance:
            print("Insufficient funds for this withdrawal.")
        else:
            print("Withdrawal amount must be greater than 0.")

    def check_balance(self):
        print(f"Account holder: {self.account_holder}, Balance: ${self.balance}.")


# Create an object
account = BankAccount("rahul", 10000)
account.deposit(15000)
account.withdraw(20000)
account.check_balance()  # Don't forget parentheses () here!