# Experimental Analysis for the Website Subsystem 
## Experiment Description
In order to ensure that the constraints set out in the Detailed Design were met, we needed to design experiments to analyze each specific constraint. Some of these constraints were simple enough to analyze, being pass/fail tests -- either they were met or they were not. The others needed some more thought to figure out how to prove it. The real-time constraint is dependent on other systems meeting their timing constraints (albeit very loosely), while the final constraint is purely opinionated, meaning we needed to get input from users to see if they felt the constraint was met. 

### Summary
As stated, the first two constraints were pass/fail. There was very little experiment designed to see whether or not they were met. The first constraint is a function built into the website that works as intended, while the second is a pass/fail value assigned to the HTML file based on its contents. This is as far as the experimentation really goes for these two. 

The third constraint required us to measure the time between signal acquisition and the time it popped up on the map. We know that from the moment the decoded packet enters the network, it takes a very small amount of time (easily less than a second) to be received and inserted into the database. At this point, the data is ready to be loaded onto the website, and will be the next time the map refreshes. As of right now, the map reloads every 10 seconds, so this constraint is met. This could easily be reduced to refreshing at a much faster rate, but would quickly eat away at our monthly budget in API calls.

The experiment designed to test the final constraint was simple. We let people connect to the website and use it, with minimal assistance. We then asked them if they felt that the experience was intuitive or not, and for any feedback that they wanted to share. 

#### Subsystem(s) Involved:
- Website
- Database

#### Constraints Tested:
- The system shall allow campus police to authorize specific drones for permitted flights in a specified time frame.
- The website will be constructed to comply with standards put into place by the W3C (World Wide Web Consortium).

- Real-time is defined as less than or equal to ten seconds. The system shall notify campus police and display data in 'real-time' on the website.
- The drone information will be displayed on the website concisely, allowing for utilization with minimized training. To reduce clutter, a user-selected option shall be implemented to view all detected drone flights (authorized and unauthorized).

 
#### Expected Result(s):
- Ideally, if the first constraint is met, we will be able to see the update on the database side of things when a user elevates a drone to the authorized status. 
- The second constraint will be tested by uploading our index.html file to the W3C HTML validator. The code is expected to pass with no critical errors.
- The third constraint is a little tricky to measure, but it is satisfied. The database loads in the received packets soon after they are sent. By refreshing the Map call on the webpage every 10 seconds, we hope that any new/modified data is loaded into the site within the allotted time.
- The final constraint was measured by allowing users to utilize the website without training and recording any feedback they had. We expect that they will find the site easy to use and pretty self-explanatory.  

## Experimental Procedure

**Testing Constraints 1 and 3**
- Number of trials: 1
1. We set the website up and loaded up the node.js server terminal.
2. When a change was made on the website, we looked at the node.js terminal to see if the changes were reflected in their respective places.

**Testing Constraint 2**
- Number of trials: 1
1. We uploaded the index.html file to the W3C Markup Validation Service via the "Validate by File Upload" tab.
2. The service let us know whether or not the HTML was valid. 

**Testing Constraint 4**
- Number of trials: 5
1. To begin the experiment, the testees were given instructions on how to access the website. They were told to attempt a log-on from any location where they could be connected to EagleNet, the network that the website is hosted on. 
2. Then, we provided them with the password needed to access the website.
3. The users were then all given a survey where they were asked questions about how easy the website was to use, and that data was tabulated.


## Experimental Data
**node.js output**<br />
![image](https://github.com/user-attachments/assets/115d44c8-eca0-4eb2-842d-d424fc9a1503)

**HTML Checker Output**
![image](https://github.com/user-attachments/assets/26d35979-c7d7-44e2-a1f1-2fc5f4c8ab13)

**Survey Feedback**
![image](https://github.com/user-attachments/assets/98833b71-5b41-4c4a-b082-975f3211b7d9)
![image](https://github.com/user-attachments/assets/71b1288b-ba61-4527-8496-2b656ef5ab93)

## Conclusions
#### Interpretation of Data

**node.js Data**
The node.js output shows the changes reflected in the database as it gets updated. As you can see when a change is made, the update is shown in the terminal. This certifies that constraints 1 and 3 are indeed met.

**HTML data**
The HTML Web Checker validated our website HTML file, which certifies that constraint number 2 was met.

**Survey Data**
The survey got overwhelmingly positive reviews, and -- as you can see -- everyone surveyed agreed that the website worked exactly as intended. I believe that this is satisfactory to show that constraint number 4 is met. 

#### Final Thoughts
Yes! All of the constraints that we tested were met, as proven by the results of these experiments. 
