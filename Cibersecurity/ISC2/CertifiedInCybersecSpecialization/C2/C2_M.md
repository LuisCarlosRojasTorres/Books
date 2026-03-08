- [Course Introduction](#course-introduction)
  - [Course Introduction](#course-introduction-1)
- [Incident Response](#incident-response)
  - [Incident Response](#incident-response-1)
  - [Incident Terminology](#incident-terminology)
  - [The Goal of Incident Response](#the-goal-of-incident-response)
  - [Components of the Incident Response Plan](#components-of-the-incident-response-plan)
  - [Self Check: Incident Response Terms](#self-check-incident-response-terms)
  - [Incident Response Team](#incident-response-team)
- [Business Continuity (BC)](#business-continuity-bc)
  - [The Goal of Business Continuity](#the-goal-of-business-continuity)
  - [Components of a Business Continuity Plan](#components-of-a-business-continuity-plan)
  - [Self Check: Common BC Components](#self-check-common-bc-components)
  - [Business Continuity in Action](#business-continuity-in-action)
- [Disaster Recovery (DR)](#disaster-recovery-dr)
  - [The Goal of Disaster Recovery](#the-goal-of-disaster-recovery)
  - [Components of a Disaster Recovery Plan](#components-of-a-disaster-recovery-plan)
  - [Self Check: Components of DR](#self-check-components-of-dr)
  - [Disaster Recovery in Action](#disaster-recovery-in-action)
- [Incident Response, Business Continuity, and Disaster Recovery Review](#incident-response-business-continuity-and-disaster-recovery-review)
  - [Course Summary](#course-summary)
  - [Terms and Definitions](#terms-and-definitions)
  - [Incident Response, Business Continuity, and Disaster Recovery Quiz](#incident-response-business-continuity-and-disaster-recovery-quiz)
  - [Incident Response, Business Continuity \& Disaster Recovery Concepts Quiz](#incident-response-business-continuity--disaster-recovery-concepts-quiz)


## Course Introduction

### Course Introduction

## Incident Response

### Incident Response

**Terminology**
- Incident: it is an occurrence that actually or ​potentially jeopardizes the confidentiality integrity or ​availability of an information system. ​The system itself or ​the information that the system processes the information it stores or transmits. ​Or something that constitutes a violation or imminent threat of violation ​of security policy, security procedures or acceptable use policies.
- Incident Response: Implies the adverse event has already ocurred and we are now responding:
  - The opportunity to plan has passed:
    - Important to have planned and prepared prior to the incident ocurring.
    - If we havent planned we pay high price.
    - If we have planned, our investment pays dividends.
- Zero Day: 
  - A new threar that is Not yet registered or recognized.
  - A formally recognized threat is issued a unique reference number.
  - particularly damaging.
  - dont have all the tools we need to detect an incident that is happening.
- Vulnerability:
  - Weakness in a system that can be exploited by a threat
- Threat/Threat actor
  - Threat actor: somebody with a motive, trying to cause disruption, destruction or theft.
- Breach: 
  - broad term used for many types of cibersecurity compromises
  - Media-information breaches
  - A breach of confidentiality: confidential information has been disclosed.
- People:
  - Computer Incident Response Team (CIRT): the team formed to respond to incidents.

**Incident Response Life Cycle**
1. Preparing for the incident
2. Incident occurs - need to detect and analyze
3. Contain to prevent further damage and eradicate to recover back to normal operations
4. Quickly take a look at what happened to better prepare to the next incident. 

**Incident Response Communications**
- Single voice. single message, clarity, single source of information.
- Internal communication. Business language/direct.
- External communication. Align with public relations message, consider all stakeholders.
  - Customers
  - Supply chain/logistics
  - Shareholders
  - Regulators
- Regular communication - even if nothing new.

**Incident Response Plan**
- Who is involved
- Relevant equipment, policies and procedures.
  - Regular training is imperative
- Links to Business Continuity (BC) and Disaster Recovery (DR) capabilities and plans.
- When to invoke and escalate (depends on the impact)
  - Judgement made by senior manager.

### Incident Terminology

While security professionals strive to protect systems from malicious attacks or human carelessness, inevitably, despite these efforts, things go wrong. For this reason, security professionals also play the role of first responders. An understanding of incident response starts with knowing the terms used to describe various cyberattacks.

- **Breach**: The loss of control, compromise, unauthorized disclosure, unauthorized acquisition, or any similar occurrence where: a person other than an authorized user accesses or potentially accesses personally identifiable information; or an authorized user accesses personally identifiable information for other than an authorized purpose. NIST SP 800-53 Rev. 5
- **Event**: Any observable occurrence in a network or system. NIST SP 800-61 Rev 2
- **Exploit**: A particular attack. It is named this way because these attacks exploit system vulnerabilities.
- **Incident**: An event that actually or potentially jeopardizes the confidentiality, integrity or availability of an information system or the information the system processes, stores or transmits.
- **Intrusion**: A security event, or combination of events, that constitutes a deliberate security incident in which an intruder gains, or attempts to gain, access to a system or system resource without authorization. IETF RFC 4949 Ver 2
- **Threat**: Any circumstance or event with the potential to adversely impact organizational operations (including mission, functions, image or reputation), organizational assets, individuals, other organizations or the nation through an information system via unauthorized access, destruction, disclosure, modification of information and/or denial of service. NIST SP 800-30 Rev 1
- **Vulnerability**: Weakness in an information system, system security procedures, internal controls or implementation that could be exploited by a threat source. NIST SP 800-30 Rev 1
- **Zero Day**: A previously unknown system vulnerability with the potential of exploitation without risk of detection or prevention because it does not, in general, fit recognized patterns, signatures or methods.

What does incident response in cybersecurity look like? No 911 calls have reported an incident. No ambulances or fire engines are coming to the rescue. It's up to the cybersecurity professionals to detect and respond to incidents.

### The Goal of Incident Response
Every organization must be prepared for incidents. Despite the best efforts of an organization’s management and security teams to avoid or prevent problems, it is inevitable that adverse events will happen that have the potential to affect the business mission or objectives.

The priority of any incident response is to protect life, health and safety. When any decision related to priorities is to be made, always choose safety first.

The primary goal of incident management is to be prepared. Preparation requires having a policy and a response plan that will lead the organization through the crisis. Some organizations use the term “crisis management” to describe this process, so you might hear this term as well.

An event is any measurable occurrence, and most events are harmless. However, if the event has the potential to disrupt the business’s mission, then it is called an incident. Every organization must have an incident response plan that will help preserve business viability and survival.

The incident response process is aimed at reducing the impact of an incident so the organization can resume the interrupted operations as soon as possible. Note that incident response planning is a subset of the greater discipline of business continuity management (BCM), which we will cover shortly.

### Components of the Incident Response Plan
The incident response policy should reference an incident response plan that all employees will follow, depending on their role in the process. The plan may contain several procedures and standards related to incident response. It is a living representation of an organization’s incident response policy.

The organization’s vision, strategy and mission should shape the incident response process. Procedures to implement the plan should define the technical processes, techniques, checklists and other tools that teams will use when responding to an incident.

To prepare for incidents, here are the components commonly found in an incident response plan:

1. Preparation
   - Develop a policy approved by management.
   - Identify critical data and systems, single points of failure.
   - Train staff on incident response.
   - Implement an incident response team. (covered in subsequent topic)
   - Practice Incident Identification. (First Response)
   - Identify Roles and Responsibilities.
   - Plan the coordination of communication between stakeholders.
      - Consider the possibility that a primary method of communication may not be available.
2. Detection and Analysis
   - Monitor all possible attack vectors.
   - Analyze incident using known data and threat intelligence.
   - Prioritize incident response.
   - Standardize incident documentation.
3. Containment, Eradication and Recovery
   - Gather evidence.
   - Choose an appropriate containment strategy.
   - Identify the attacker.
   - Isolate the attack.
4. Post-Incident Activity
   - Identify evidence that may need to be retained.
   - Document lessons learned.
- Retrospective
   - Preparation
   - Detection and Analysis
   - Containment, Eradication and Recovery
   - Post-incident Activity

NIST Computer Security Incident Handling Lifecycle. NIST SP 800-61 Rev. 2


### Self Check: Incident Response Terms

### Incident Response Team

## Business Continuity (BC)

### The Goal of Business Continuity

### Components of a Business Continuity Plan

### Self Check: Common BC Components

### Business Continuity in Action

## Disaster Recovery (DR)

### The Goal of Disaster Recovery

### Components of a Disaster Recovery Plan

### Self Check: Components of DR

### Disaster Recovery in Action

## Incident Response, Business Continuity, and Disaster Recovery Review

### Course Summary

### Terms and Definitions

### Incident Response, Business Continuity, and Disaster Recovery Quiz

### Incident Response, Business Continuity & Disaster Recovery Concepts Quiz

