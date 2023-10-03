
def main():

    n = int(input("Input a row number: "))

    print(f"Sum: {sum_odd_numbers(n)}")


def sum_odd_numbers(n):
    # Check if the number is a positive integer
    try:
        if n <= 0:
            raise ValueError
        else:
            return n ** 3
    except ValueError:
        print("Value should be a positive integer greater than zero.")
        exit(0)


if __name__ == "__main__":
    main()
