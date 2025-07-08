T_up = 1s
T_DB = 3

CurrentAlarmList: ela vem em cada iteração.
1. 1,2
2. 1,3
3. 1,3,5
4. 2,3,5 

`this.ActiveAlarmList`: operation: "tem no `currentAL` e tem no `this.ActiveAL`"
`this.NewActiveAlarmList`: operation: "tem no `currentAL` mas nao tem no `this.ActiveAL`"
`this.NonActiveAlarmList`: operation: "nao tem no `currentAL` mas tem no `this.ActiveAL`"


1. t= T_up
  - Initial state:
    - `currentAlarmList`: 1,2
    - `this.ActiveAlarmList`: empty
    - `this.NewActiveAlarmList`: empty
    - `this.NonActiveAlarmList`: empty
  - After operations:
    - `currentAlarmList`: 1,2
    - `this.ActiveAlarmList`: empty
    - `this.NewActiveAlarmList`: 1,2
    - `this.NonActiveAlarmList`: empty
2. t= 2T_up
  - Initial state:
    - `currentAlarmList`: 1,3
    - `this.ActiveAlarmList`: empty
    - `this.NewActiveAlarmList`: 1,2
    - `this.NonActiveAlarmList`: empty
  - After operations:
    - `currentAlarmList`: 1,3
    - `this.ActiveAlarmList`: 1
    - `this.NewActiveAlarmList`: 3
    - `this.NonActiveAlarmList`: 2
2. t= 3T_up
  - Initial state:
    - `currentAlarmList`: 1,3,5
    - `this.ActiveAlarmList`: empty
    - `this.NewActiveAlarmList`: empty
    - `this.NonActiveAlarmList`: empty
  - After operations:
    - `currentAlarmList`: 1,3,5
    - `this.ActiveAlarmList`: empty
    - `this.NewActiveAlarmList`: 1,2
    - `this.NonActiveAlarmList`: empty



