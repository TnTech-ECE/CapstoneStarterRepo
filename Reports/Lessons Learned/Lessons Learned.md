# Lessons Learned

This document should be used as an ongoing documentation of the following:

- Reflect on the project, both technical and organizational. What went well? What didn’t go well? 
- What unanticipated problems occurred? 
- What would you do differently if you were to do it over again? 
- What “best practices” have you identified? 
- What words of wisdom would you pass on to future students?

Create a section addressing each of the above questions. 

## What went well
- Meeting for at least an hour twice a week worked well during the first semester of progress. This allowed us to make significant progress between every meeting. In the first semester communication was also better overall which allowed us to find and tweak errors effectively. 
## What didn't go well
- Our team's communication went down during the second semester due to us having different schedules.
- We waited to experimentally test our subsystems for too long. We waited for each subsystem to be individually tested to work, but one of them never ended up working, meaning we were very late to test everything together. We had a period where the team lost significant motivation during the signoff phase which delayed the approval of our designs. A lack of communication during the design phase also meant that there were many errors made that were not found and subsequently affected the implementation phase. 
## Unanticipated problems 
- Arduino Uno Wifi Rev2's SPI bus does not connect to the same pins as Arduino R3 despite pinout on website saying so. This is according to full schematic and several forums.
- Components
- The Blackfin DSP SPI was a significant issue and was unable to be properly interfaced with the Arduino SPI after about a month of trying to debug it.
- The power subsytem design was rushed which when hooked up destroyed the input subsystem PCB and electrocuted one of the team members
- There were not defined supply and I/O ports on the input and error PCBs along with the fact that the polarization of some of the capacitors was flipped on the physical PCB which made the 
  implementation very difficult.

## What we would do differently
- Spend a group session formulating permanent weekly meeting plans once we realize that our schedules did not synergize at all. 
- We would recommend having a signoff that specifically focuses on how each subsystem physically connects to each other, i.e. adaptors, jumper cables, power connections, physical placement, etc.
## "Best practices" we have identified
- 
## Words of Wisdom
- Buy as many pre-built parts as possible that work within the necessary parameters.
- Communicate extensively during the design/signoff phase especially to pinpoint possible issues in the overall design.
- Prioritize the most critical parts of your system first.
- Manage and organize your time throughout the two semesters well (With a Gantt chart for example).
