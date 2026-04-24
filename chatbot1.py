# Bank Chatbot using Python NLTK Library

# Install nltk first:
# pip install nltk

import nltk
from nltk.chat.util import Chat, reflections

# Define conversation pairs for Bank Bot
pairs = [

    [
        r"my name is (.*)",
        ["Hello %1, Welcome to ABC Bank. How can I help you today?"]
    ],

    [
        r"hi|hello|hey",
        ["Hello! Welcome to ABC Bank.", 
         "Hi there! How may I assist you today?"]
    ],

    [
        r"what is your name ?",
        ["I am Bank Bot, your virtual banking assistant."]
    ],

    [
        r"how are you ?",
        ["I am fine. Thank you! How can I help you today?"]
    ],

    [
        r"(.*)open(.*)account(.*)",
        ["You can open a Savings or Current account by visiting nearest branch with Aadhaar and PAN card."]
    ],

    [
        r"loan",
        ["We provide Home Loan, Car Loan and Personal Loan. Please tell me which loan you need."]
    ],

    [
        r"home loan",
        ["Home loan interest starts from 8.5% per annum."]
    ],

    [
        r"car loan",
        ["Car loan interest starts from 9% per annum."]
    ],

    [
        r"personal loan",
        ["Personal loan interest starts from 11% per annum."]
    ],

    [
        r"balance enquiry",
        ["Please login to mobile banking app or visit nearest ATM for balance enquiry."]
    ],

    [
        r"credit card",
        ["We offer Silver, Gold and Platinum credit cards."]
    ],

    [
        r"debit card",
        ["Debit card will be issued instantly after account opening."]
    ],

    [
        r"branch location",
        ["Please visit our website and use Branch Locator service."]
    ],

    [
        r"timing",
        ["Bank timings are Monday to Friday, 10 AM to 4 PM."]
    ],

    [
        r"thank you|thanks",
        ["You are welcome!", "Happy to help you!"]
    ],

    [
        r"bye|quit|exit",
        ["Thank you for visiting ABC Bank. Have a nice day!"]
    ],

    [
        r"(.*)",
        ["Sorry, I didn't understand that. Please ask banking related queries."]
    ]

]

# Create chatbot
bank_bot = Chat(pairs, reflections)

# Start chatbot
print("Welcome to ABC Bank Chatbot")
print("Type 'bye' to exit\n")

bank_bot.converse()