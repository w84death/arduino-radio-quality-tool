# Radio Quality Tool

## Usage

Open any text editor and keep focus on it. Output will be typed there.

Press A button to start. Then (there's 1000ms delay) press and keep pressed all the time button B. The tool will measure how many signals (PIN HIGH) it receives in 1000 intervals. To end release B and press A again. Last result will be throw away because it's a little delay between release the send button and receive the stop button.

## Example output

```
---------------------------------------
  KEEP B PRESSED TO SEND SIGNALS
---- START ----------------------------

  RECIEVED: 1000 / 1000
  RECIEVED: 1000 / 1000
  RECIEVED: 1000 / 1000
  RECIEVED: 728 / 1000
  RECIEVED: 570 / 1000
  RECIEVED: 932 / 1000
  RECIEVED: 736 / 1000
  RECIEVED: 831 / 1000
  RECIEVED: 889 / 1000
  RECIEVED: 858 / 1000
  RECIEVED: 743 / 1000
  RECIEVED: 885 / 1000
  RECIEVED: 854 / 1000
  RECIEVED: 527 / 1000
  RECIEVED: 666 / 1000
  RECIEVED: 454 / 1000
  RECIEVED: 703 / 1000
  RECIEVED: 535 / 1000
  RECIEVED: 836 / 1000
  RECIEVED: 803 / 1000
  RECIEVED: 1000 / 1000
  RECIEVED: 175 / 1000

---- END --- LAST RESULT IS OMITTED ---

  REPORT: 16550 / 21000 => 78.81% <=

---------------------------------------
```

In this example I was near the receiver but then I put the antenna in to the metal military cup (thick walls).