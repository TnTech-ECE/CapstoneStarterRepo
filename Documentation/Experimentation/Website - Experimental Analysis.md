# Experimental Analysis for the Website Subsystem 
## Experiment Description
### Summary
<!-- Short summary of the experiment written after completing it -->

#### Subsystem(s) Involved:
- Website
- Database

#### Constraints Tested:
- The system shall allow campus police to authorize specific drones for permitted flights in a specified time frame.
- The website will be constructed to comply with standards put into place by the W3C (World Wide Web Consortium).

- Real-time is defined as less than or equal to ten seconds. The system shall notify campus police and display data in 'real-time' on the website.
- The drone information will be displayed on the website concisely, allowing for utilization with minimized training. To reduce clutter, a user-selected option shall be implemented to view all detected drone flights (authorized and unauthorized).

 
#### Expected Result(s):
- The first constraint 
- The second constraint will be tested by uploading our index.html file to the W3C HTML validator. The code is expected to pass with no critical errors.
- The third constraint is a little tricky to measure, but it is satisfied. The database loads in the received packets soon after they are sent. By refreshing the Map call on the webpage every 10 seconds, we hope that any new/modified data is loaded into the site within the alloted time.
- The final constraint was measured by allowing users to utilize the website with no training, and recording any feedback they had. We expect that they will find the site easy to use and pretty self-explanatory.  

## Experimental Procedure
<!-- Description of what you did ideally in steps -->


**Testing Constraint 5**
Since these constraints cannot be analyzed quantitatively, we decided to test these constraints in a more qualitative way. To do this, we found people who have, at most, surface-level knowledge of our project and asked them to use our website. Then, we asked them to decide whether or not it meets the constraints put forth.

- Number of trials: 5
1. To begin the experiment, the testees were given instructions on how to access the website. They were told to attempt a log-on from any location where they could be connected to EagleNet, the network that the website is hosted on. 
2. Then, we provided them with the password needed to access the website.
3. The users were then all


## Experimental Data
<!-- data tables or graph of the results (whichever is appropriate) -->

## Conclusions
#### Interpretation of Data
<!-- explain what the results of the experiments mean and what conclusions you draw -->

#### Final Thoughts
<!-- Were constraints met? -->
