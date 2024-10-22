while True:
    email = input("Write your email adress: ").lower()
    index = email.find('@')
    if index != 0 and index != -1:
        userName, mailDomain = email.split("@")
        domain = "www."+userName+".com"
        print("Your username is:", userName, "and domain is:", mailDomain)
        print("Your website domain is: ", domain)
        break
    else:
        print("Invalid input, please write our email")
