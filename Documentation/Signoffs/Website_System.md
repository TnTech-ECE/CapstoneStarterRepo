# Website_System
## Functionality
The purpose of the website subsystem is to allow a designated user to access the drone data stored in the database subsystem. The website will check the database for new information at a speed that will allow any new drones logged to be discovered by the police in as close to real-time as possible. The accessed data will be displayed to the user in a clean, concise manner that allows for the timely, efficient management of dispatcher resources. The website will enable the end user to authorize drones for flight so that there is a way to obtain approval for necessary flights. Our system will capture images of the drone or the drone operator, based on certain physical limitations, which will be displayed alongside the location of the drone and the operator on our interactive map. If our system malfunctions, the end user will also be able to determine the system's health via the website to pinpoint where the problem occurred. All data collected will be retained and deleted in compliance with Tennessee Technological University policies, specifically Policy 113.    

## Constraints
| No.| Constraint | Origin |
| -- | --------- |--------|
|  1 | The database must be accessed through a website instead of a mobile phone application. | Campus Police |
|  2 | Real-time is defined as less than or equal to ten seconds. The system shall notify campus police and display data in 'real-time' on the website. | Project Team / Campus Police |
|  3 | The drone information will be displayed on the website concisely, allowing for utilization with minimized training. To reduce clutter, a user-selected option shall be implemented to view all detected drone flights (authorized and unauthorized). | Project Team |
|  4 | The website will be constructed securely, within reason. | Project Team |
|  5 | The website will be constructed to comply with standards put into place by the W3C (World Wide Web Consortium). | Project Team / Supervisor |
|  6 | The system shall allow campus police to authorize specific drones for permitted flights in a specified time frame. | Project Team |  
|  7 | The system shall increase the alert's urgency if a drone is detected in any designated geographical region. | Project Team |  

<sup>1</sup> For the safety of officers in the field, the campus police department has requested that the obtained Remote ID (RID) data be displayed on a website as opposed to a mobile application. Citing concerns about officers utilizing personal mobile devices in the field, the police captain and dispatcher we met with expressed an explicit desire for a website-based information display. For the data to get to officers in the field, a dispatcher will relay information regarding the drone to the officer.

<sup>2</sup> To allow for the timely dispatch of officers to the location of the detected drone, the campus police department has requested that the system operate as close to real-time as possible. Upon initial detection of a given Remote ID signal, a notification will be issued to the TTU police department. While this is significantly longer than real-time is normally defined to be, we feel that for this project, this is a reasonable amount of time. At world-record speeds, a drone pilot would at most be able to move 0.075 miles away on foot. This gives ample time for the system to detect and report the drone, and allows the dispatcher to provide updates on significant movements. 

<sup>3</sup> To allow for easy integration into the campus police department's workflow, the system will be designed in a way so that minimal training is required for operation. A user should be able to look at the website and obtain a general idea of everything that is there and how to utilize it. Certain toggles to display/hide data may be implemented for the clarity of the website, and these should be intuitive for the user. 

<sup>4</sup> To prevent the unauthorized access of data in our database, the website hosting the data must be constructed securely, to a reasonable standard. Of course, nothing can be 100% secure, so it would be remiss to say that our website is "totally secure", but it will be constructed in such a way that it is difficult for malicious entities to gain access. One such way we can secure our website would be to add a password to it that would allow only authorized users to gain access to it. Another way that we may certify our website is secure is by using Google's Safe Browsing website checker.

<sup>5</sup> The W3C is a non-profit organization that works to develop standards for the World Wide Web. To be certain that our website is accessible, private, and secure, we can utilize validators created by the W3C to verify our website is ready for use on any device. Our team will subject the website to at least three validators provided by the W3C - the Nu HTML checker, the Link checker, and the CSS validator.  

<sup>6</sup> To abstain from sending unnecessary alerts to campus police, we have decided to implement the ability to let campus police whitelist drone serial numbers. This will prevent alerts from being generated when an authorized drone is detected. Adding this check will also increase the execution time for the program, but again, it should still take less than the allocated time. This authorization will set a value in our database that will allow the website to quickly display detected drones based on whether or not they are authorized for flight.

<sup>7</sup> Privacy on campus is a big concern for this project. One of the main concerns with drones on campus is that some malicious users may utilize drones to enter or obtain a clear view of private areas. To combat this, we will designate certain areas on campus as high-priority areas and raise the priority level of any drone that enters these locations. This allows police to make informed decisions about what order to operate in. Our team argues that the most malicious drones will likely be flown in these designated "high-risk" areas, and believes that the safety of students located in these areas is of the utmost importance. 

## Schematic
<img src="/Documentation/Images/flow_control_v3.png" >

### Rough Website Design
<img src="/Documentation/Images/website_beta.png" >

### HTML/CSS and JavaScript

The languages chosen to implement this program will be HTML, CSS, and JavaScript. HTML will be used initially to create the framework of the webpage, where CSS will then be utilized to make the page look more presentable and coherent with Tech's current website theme. JavaScript will be implemented where necessary to make the webpage responsive to user inputs. In our case, that would allow the user to select a drone to view details on, view locations on the map, promote a drone's priority status, and other such tasks.

### Google Maps API
We have decided to use Google's Maps JavaScript API to handle the placement of drones in the correct places on the map. Google allows users to utilize up to $200 monthly worth of Maps API resources for free, with the credit resetting on the first of each month. This amount of money covers nearly 30,000 map loads per month.[^1] With this API, a map can be centered on the campus of TTU, and, using the coordinates retrieved from the Remote ID signal, markers can be placed on the map in the exact location where the drone is detected. 

After obtaining an API key, we can implement the API call using the key in the HTML5 webpage, where the map will then become usable in the browser. The Maps JavaScript API allows up to 300 calls per minute per IP address.[^2] This means that the absolute maximum number of times the website can call the API is 5 times per second. Assuming that the API is called a generous 500 times per day, then in even the longest months, the most API calls the program will make will be 15,500. For the first 100,000 API calls each month, the cost per call is 0.007 USD. This means that even with a very high number of API calls, let's say 500, just over half of our built-in API budget is used.

The program will then prompt the database for all data sets that match the search characteristic (default value is set to the current date.) These data points will then have a Google Maps marker placed on their respective locations. The dispatcher can then select a certain drone and view the related data received from the Remote ID. Drones will populate the list in the reverse order they were detected, with the most recent drones appearing first.

For the website to be accessible at all times, it will need to be hosted on a machine that doesn't turn off. We hope to host the website on a Raspberry Pi 5, the same machine that is hosting our database server. This will make the access of data from the database much easier. The cost of this service is to be integrated into the subsystem's budget, and is not expected to cost a significant amount of money, likely less than $30 per year that the site is hosted. 

## Analysis

The implementation of the website subsystem will require a few different processes to all work together. These processes are detailed below.

### Testing

To ensure the website's proper operation, a wide variety of test cases will be used for thorough testing. The initial test will be conducted using a set of valid and invalid login data. Utilizing this pair of login keys, we will be able to check whether or not the website is accurately allowing only authorized users to access it. Once we have verified that only authorized users can use the site, we will move on to testing the other features of the website. 

At this point in the program's execution, we can use a dummy database filled with data that we create to verify the correct operation of the website. Some of this data will be created to hinder the program, which will result in errors being generated and handled correctly. If the program can sufficiently handle all of the erroneous cases, then it will certainly be able to handle the data received from the database subsystem. 

To be certain that our [constraints](#constraints) are met, experiments will be conducted and data will be collected to prove that the subsystem operates as we have declared it will. The first three constraints can be validated by launching a Remote ID compliant drone and seeing how long it takes our system to detect it. Constraint four is difficult to quantify, and will instead be tested by asking someone from campus police to demo the website. Feedback received from the user will be used to adapt the website to their liking. The next constraint is more difficult to prove. One way that the team has discussed proving this constraint has been met is by asking CEROC (the Cybersecurity Education, Research, and Outreach Center) here at Tennessee Tech to try to break into our website. This activity will provide validation that a "reasonable level" of security has been met. 

Constraint number six will be tested by running our website through the [Markup Validation Service](https://validator.w3.org/#validate_by_uri) provided by w3.org. This validator will display any errors that may prevent the website from operating properly on certain browsers/systems. The final two constraints can again be tested utilizing a Remote ID compliant drone. By using a drone whose serial number is known, we can provide authorization to it and see if our system behave as expected when an authorized drone is detected. After revoking this drone's authorization, we can then test our status elevation system by flying the drone into a designated area. If the drone is shown as having an elevated status, then the team will know that the constraint has been met and that our system functions as intended.

A more detailed testing regimen will be developed as the website becomes more and more refined. This process is iterative, and functionality, while laid out amicably above, is not definite yet. There are some processes that the team is not entirely sure if they want to include, and will be more along the lines of quality-of-life features. Rigorous testing procedures for these features will be created alongside the features themselves, demonstrating the precise execution of our code.

## BOM
| Item     | Part Number | Quantity | Price/Unit     | Total Cost |
| -------- | ------------| -------- |----------------|------------|
|Domain    |            -|         1|        $30/year|         $30|
|Total     |             |          |                |            |

## References
<!-- This is how to do footnotes for the references: --> 
[^1]: (https://mapsplatform.google.com/pricing/)
[^2]: (https://developers.google.com/maps/documentation/javascript/usage-and-billing)
<!--etc.-->
