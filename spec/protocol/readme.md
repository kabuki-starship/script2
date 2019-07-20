# [SCRIPT Specification RFC](../readme.md)

## License

Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>; All right reserved (R).

This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain one at [https://mozilla.org/MPL/2.0/](https://mozilla.org/MPL/2.0/).

## [SCRIPT Protocol](readme.md)

The Serial Chinese Room, Interprocess, and Telemetry (SCRIPT) Specification consists of the Automaton Standard Code for Information Interchange Data Specification, the Universal Addressing Specification, and the Chinese Room Abstract Stack Machine (Crabs) Specificaiton.

In the John Searle's famous Chinese Room Thought Experiment users may talk to the Chinese Room (i.e. end-point) by writing Messages (i.e. Datagrams) on a piece of Paper (B-Input) and passing them through a Slot (i.e. Socket) in a Door (Group of communication links leading to the same room) in the room. An Agent then reads the message and uses them to operate the Crabs, and replies by writing a Message on a piece of Paper and passing it back through the Slot.

### Content Table

1. [ASCII Data Specification](./ascii_data/readme.md)
1. [Universal Addressing Specification](./universal_addressing.md)
1. [Crabs Specification](./crabs/readme.md)