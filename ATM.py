class ATM:
    def __init__(self):
        self.account_no = 0
        self.name = ""
        self.pin = 0
        self.balance = 0.0
        self.mobile_no = ""

    def set_data(self, account_no_a, name_a, pin_a, balance_a, mobile_no_a):
        self.account_no = account_no_a
        self.name = name_a
        self.pin = pin_a
        self.balance = balance_a
        self.mobile_no = mobile_no_a

    def get_account_no(self):
        return self.account_no

    def get_name(self):
        return self.name

    def get_pin(self):
        return self.pin

    def get_balance(self):
        return self.balance

    def get_mobile_no(self):
        return self.mobile_no

    def set_mobile(self, mob_prev, mob_new):
        if mob_prev == self.mobile_no:
            self.mobile_no = mob_new
            print("\nSuccessfully Updated Mobile no.")
        else:
            print("\nIncorrect !!! Old Mobile no")

    def cash_withdraw(self, amount_a):
        if 0 < amount_a < self.balance:
            self.balance -= amount_a
            print("\nPlease Collect Your Cash")
            print(f"Available Balance: {self.balance}")
        else:
            print("\nInvalid Input or Insufficient Balance")


def main():
    user1 = ATM()
    user1.set_data(404402, "User", 1111, 45000.90, "8867983747")

    while True:
        enter_account_no = int(input("\n****Welcome to ATM*****\nEnter Your Account No: "))
        enter_pin = int(input("Enter PIN: "))

        if enter_account_no == user1.get_account_no() and enter_pin == user1.get_pin():
            while True:
                print("\n**** Welcome to ATM *****")
                print("Select Options ")
                print("1. Check Balance")
                print("2. Cash withdraw")
                print("3. Show User Details")
                print("4. Update Mobile no.")
                print("5. Exit")

                choice = int(input())

                if choice == 1:
                    print(f"\nYour Bank balance is: {user1.get_balance()}")

                elif choice == 2:
                    amount = int(input("\nEnter the amount: "))
                    user1.cash_withdraw(amount)

                elif choice == 3:
                    print("\n*** User Details are:")
                    print(f"-> Account no: {user1.get_account_no()}")
                    print(f"-> Name: {user1.get_name()}")
                    print(f"-> Balance: {user1.get_balance()}")
                    print(f"-> Mobile No.: {user1.get_mobile_no()}")

                elif choice == 4:
                    old_mobile_no = input("\nEnter Old Mobile No.: ")
                    new_mobile_no = input("Enter New Mobile No.: ")
                    user1.set_mobile(old_mobile_no, new_mobile_no)

                elif choice == 5:
                    exit()

                else:
                    print("\nEnter Valid Data !!!")

        else:
            print("\nUser Details are Invalid !!!")


if __name__ == "__main__":
    main()
