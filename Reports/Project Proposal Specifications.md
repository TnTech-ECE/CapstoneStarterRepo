# Project Proposal

This document provides a comprehensive explanation of what a project proposal should encompass. The content here is detailed and is intended to highlight the guiding principles rather than merely listing expectations. The sections that follow contain all the necessary information to understand the requirements for creating a project proposal.


## General Requirements for the Document
- All submissions must be composed in markdown format.
- All sources must be cited unless the information is common knowledge for the target audience.
- The document must be written in third person.
- The document must identify all stakeholders including the instuctor, supervisor, and cusotmer.
- The problem must be clearly defined using "shall" statements.
- Existing solutions or technologies that enable novel solutions must be identified.
- Success criteria must be explicitly stated.
- An estimate of required skills, costs, and time to implement the solution must be provided.
- The document must explain how the customer will benefit from the solution.
- Broader implications, including ethical considerations and responsibilities as engineers, must be explored.
- A list of references must be included.
- A statement detailing the contributions of each team member must be provided.


## Introduction

The introduction must be the opening section of the proposal. It acts as the "elevator pitch" of the project, briefly introducing the objective, its importance, and the proposed solution. Because readers may only read this section, it should effectively capture their attention and encourage them to read further.

Toward the end of the introduction, include a subsection that outlines what the proposal will cover. This helps set reader expectations for the ensuing sections.


## Formulating the Problem

Current automated chess boards are expensive and lack features such as online functionality, voice recognition, and unobstructed movement. The goal of this implementation is to improve these features, reduce cost, use accessible parts for easy hobbyist replication, and to make the game more accessible for players with disabilities. Challenges of this project include digital signal processing for voice controls, artificial intelligence (AI) implementation for solo-play, and automating piece movement. 

### Background

During the pandemic, chess increased in popularity [5]. Online chess specifically had a major influx of activity, with Chess.com adding 1 million accounts from March to November 2020, and a 2.8 million member increase in November alone [5]. This newfound popularity opens up opportunities for innovation on this classic game. An automated chess board would support primarily online chess players who want to improve their on-the-board (OTB) game.

AI has had a major impact in the world of chess, especially in the context of online play [6]. It provides learning opportunities, as certain AI can beat any human player. Chess games played OTB do not usually have this capability except for automated boards. AI in OTB implementations will allow players to improve by progressively increasing the strength of their opponent. This function would aid online players transitioning to OTB play, as they could play against AI before a human opponent. This feature also supports those who want to play OTB chess but cannot do so alone.

Many efforts have been made to ensure that chess tournaments are accommodating to those with disabilities [7]. These accommodations still could be improved upon for player autonomy and ease in preparing. For those with Alzheimer’s, other dementias, dyslexia, dysgraphia, fine/gross motor needs, who are blind, or those with a temporary disability such as a broken hand, an accommodation that can be made is the assignment of a Game Assistant (GA) [7]. In cases such as these, the GA may be needed for piece movement, clock pressing, and/or scoring [7]. An automated board could help as an alternative to a GA by helping with piece movement, automatically keeping time, and automating scoring. This would allow players more independence, as they would not have to rely on the assistance of a GA, and fewer volunteers would be needed for tournaments.

### Specifications and Constraints

Specifications and constraints define the system's requirements. They can be positive (do this) or negative (don't do that). They can be mandatory (shall or must) or optional (may). They can cover performance, accuracy, interfaces, or limitations. Regardless of their origin, they must be unambiguous and impose measurable requirements.

#### Specifications

Specifications are requirements imposed by **stakeholders** to meet their needs. If a specification seems unattainable, it is necessary to discuss and negotiate with the stakeholders.

#### Constraints

Constraints often stem from governing bodies, standards organizations, and broader considerations beyond the requirements set by stakeholders.

Questions to consider:
- Do governing bodies regulate the solution in any way?
- Are there industrial standards that need to be considered and followed?
- What impact will the engineering, manufacturing, or final product have on public health, safety, and welfare?
- Are there global, cultural, social, environmental, or economic factors that must be considered?


## Survey of Existing Solutions

Research existing solutions, whether in literature, on the market, or within the industry. Present these findings in a coherent, organized manner. Remember to cite all information that is not common knowledge.


## Measures of Success

Define how the project’s success will be measured. This involves explaining the experiments and methodologies to verify that the system meets its specifications and constraints.


## Resources

Each project proposal must include a comprehensive description of the necessary resources.

### Budget

Provide a budget proposal with justifications for expenses such as software, equipment, components, testing machinery, and prototyping costs. This should be an estimate, not a detailed bill of materials.

### Personnel

#### Required Skills  

**Software & Programming:** Programming, AI / API / Networking, MATLAB, R  
**Hardware & Systems:** Microcontroller knowledge, Embedded Systems / Digital Systems, Magnetics, Power Electronics, Mechanical Systems  
**Design & Simulation Tools:** LTspice, CAD / 3D Printing  
**Theory & Analysis:** Signal Processing  

#### Team Skills

**Nathan MacPherson**  
- *Current Skills:* Digital Systems, Programming, Networks, Electrical CAD  
- *Skills to Learn:* Magnetics, Mechanical Systems, CAD / 3D Printing  

**Noah Beaty**  
- *Current Skills:* Digital Systems, Programming, Microcontroller knowledge, R  
- *Skills to Learn:* Signal Processing, MATLAB, Mechanical Systems  

**Jack Tolleston**  
- *Current Skills:* Digital Systems, Programming, Microcontroller knowledge, R, API / Networking  
- *Skills to Learn:* AI, Embedded Systems, Magnetics  

**Allison Givens**  
- *Current Skills:* Microcontroller knowledge, Programming, CAD / 3D Printing  
- *Skills to Learn:* MATLAB, Magnetics, Power Electronics, LTspice  

**Lewis Bates**  
- *Current Skills:* Digital Systems, Embedded Systems, Microcontroller knowledge, Power Electronics, R  
- *Skills to Learn:* Signal Processing, AI, Magnetics  

*Note:* This list highlights each member’s strongest skills. Depending on the project, required skills or assignments may change.  

#### Supervisor
- **Student Success:** Chosen for potential project presentation opportunities at Tech.  

#### Instructor
- **Professor Van Neste:** Chosen to provide guidance on physical implementation.

### Timeline

Provide a detailed timeline, including all major deadlines and tasks. This should be illustrated with a professional Gantt chart.


## Specific Implications

Explain the implications of solving the problem for the customer. After reading this section, the reader should understand the tangible benefits and the worthiness of the proposed work.


## Broader Implications, Ethics, and Responsibility as Engineers

Consider the project’s broader impacts in global, economic, environmental, and societal contexts. Identify potential negative impacts and propose mitigation strategies. Detail the ethical considerations and responsibilities each team member bears as an engineer.


## References

[4] GoChess Mini. Particula. (n.d.). https://particula-tech.com/products/gochess-mini?variant=45806634402040&country=US&currency=USD&utm_medium=product_sync&utm_source=google&utm_content=sag_organic&utm_campaign=sag_organic&srsltid=AfmBOooAY445sOW--M7GA0T4jbNkHE609yl_YKlFLR9iyhF7eX9KFsd9ubc

[5] R. Lahood, "The Queen’s Gambit, the Chess Boom, and the Future of Chess," Michigan Journal of Economics, Apr. 5, 2021. https://sites.lsa.umich.edu/mje/2021/04/05/the-queens-gambit-the-chess-boom-and-the-future-of-chess/.

[6] D. M. D. Iliescu, "The Impact of Artificial Intelligence on the Chess World," *JMIR Serious Games*, vol. 8, no. 4, p. e24049, Dec. 2020. https://pmc.ncbi.nlm.nih.gov/articles/PMC7759436/.

[7] US Chess, "US Chess Guidelines for Accessible Chess Events," Apr. 2020. https://new.uschess.org/sites/default/files/wp-thumbnails/2020/04/Accessibility-Guidelines-April-2020.pdf.


## Statement of Contributions

Each team member must contribute meaningfully to the project proposal. In this section, each team member is required to document their individual contributions to the report. One team member may not record another member's contributions on their behalf. By submitting, the team certifies that each member's statement of contributions is accurate.
