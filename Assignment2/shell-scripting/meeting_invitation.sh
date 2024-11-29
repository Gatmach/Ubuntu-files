#!/bin/bash

# Subject of the email
subject="Invitation to 21st Open Webinar on Skills Optimization by JhubAfrica"

# The body of the invitation mail
message="Dear <name>,

We are inviting you as our computing student to our 21st Open Webinar on skills optimization by JhubAfrica, scheduled for Friday, 29th November from 5:00 P.M. 

The Zoom link for joining the webinar on Friday is as follows:
[Zoom Link]

We shall also broadcast the webinar on our YouTube channel. You can watch it live here:
https://youtu.be/ONVTA7LKMIs

Best regards,
The Computing Department
"

# Check if the students.txt file exists
if [ ! -f students.txt ]; then
  echo "Error: students.txt file not found!"
  exit 1
fi

# Read the students file line by line
while IFS=, read -r name email; do
  if [[ -z "$name" || -z "$email" || "$name" =~ ^# ]]; then
    continue
  fi

  # Personalize the message by replacing <name> with the student's name
  personalized_message=$(echo "$message" | sed "s/<name>/$name/g")

  echo "$personalized_message" | mail -s "$subject" "$email"

  # Print to confirm the email was sent
  echo "Invitation sent to $name at $email"
done < students.txt

echo "All invitations have been sent."

