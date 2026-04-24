print("Welcome to Hospital and Medical Expert System")

QUESTIONS = [

'Do you have fever?',
'Do you have cough?',
'Do you have chest pain?',
'Do you have breathing difficulty?',
'Do you have headache?',
'Do you have vomiting?',
'Do you have stomach pain?',
'Do you feel weakness or tiredness?',
'Are you having dizziness?'

]

THRESHOLD = {

'Mild': 20,
'Severe': 40,
'Emergency': 65

}

def expertSystem(questions, threshold):

    score = 0

    for question in questions:

        print(question + " (Y/N)")
        ans = input("> ")

        if ans.lower() == 'y':

            print("On a scale of 1-10 how serious is it?")
            ip = input("> ")

            while ((not ip.isnumeric()) or int(ip) < 1 or int(ip) > 10):

                print("Enter valid input!")
                ip = input("> ")

            score += int(ip)

        print()

    print("Total Score =", score)
    print()

    if score >= threshold['Emergency']:

        print("EMERGENCY CONDITION DETECTED")
        print("Please visit nearest hospital immediately.")
        print("Call Ambulance: 108")
        print("Recommended Department: Emergency / ICU")

    elif score >= threshold['Severe']:

        print("SEVERE HEALTH CONDITION DETECTED")
        print("Please consult a doctor as soon as possible.")
        print("Recommended Department:")
        print("- General Physician")
        print("- Chest Specialist")
        print("- Internal Medicine")

    elif score >= threshold['Mild']:

        print("MILD SYMPTOMS DETECTED")
        print("Take rest, drink water, and monitor symptoms.")
        print("If symptoms increase, visit hospital.")
        print("Recommended Facility: OPD Consultation")

    else:

        print("No major symptoms detected.")
        print("Maintain healthy lifestyle.")
        print("Visit hospital for regular health checkup.")

if __name__ == '__main__':

    print("\nWelcome to Hospital Medical Guidance System\n")
    print("Please answer all questions honestly.\n")

    expertSystem(QUESTIONS, THRESHOLD)