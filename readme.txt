This is a firmware version created by Travis Siegel (kq4dzk@softcon.com)
This is an attempt to make the Quansheng UV-K5 radio as accessible as possible.  Because we're working with prerecorded text strings (*1) it makes it difficult or impossible to represent some options in the menus, and entering new channel names, or editing existing channel information is slightly problematic.  Below, I've explained all the things I've done to make the radio as usable as I could.  Likely, others can do more, since it's likely they know more about the radio, or are better C/C++ programmers than I am.  All improvements are welcome, so don't hesitate to send modifications you think might help.  Suggestions are also greatfully accepted, but again, some things just aren't possible with the current configuration of hardware/voice capabilities.

** fixes since last release**
*Fixed the spoken frequency, so that it won't read the last two digits if they are both zero, since that doesn't really add anything to the value of the information, and it also gets you back to the radio faster. (sorry, intended to have this in before releasing the first version, but forgot to fix that before release).
*Added a beep to the start of the frequency readout if you're above the 1GHZ range, just as an auditory reminder, since the extra digit can be confusing if you're not aware of what it means.
*****

To upload this rom to the radio, you'll need a programming cable (the ones from the UV5R, which are also called kenwood style,  radio style cables will work just fine
You'll also need the k5prog_win program, since the UV-K5 official uploader program won't work, because it doesn't like the version number of the firmware.  I've included it with this archive, because I don't know the url of where I obtained it, although the documentation does mention this url that it derived it work from: https://github.com/sq5bpf/k5prog.
Running the k5prog_win program is simple enough, just execute it, click (or tab to), the "Write Firmware" button, and click it.  Then, select the com port the radio is connected to (this may take some guess work if you're not familiar with your computer.  Chances are though, it's going to be the largest numbered port currently showing after selecting the com option).  Then press the browse button (for screen readers, it's the only unlabeled button there, so it's easy enough to find), then select open after you've located the firmware.bin file.  This will start the upload of the firmware to the radio, providing the radio is in firmware mode (that's not it's real name, but we'll just go with that).
You can get to this mode by holding down the push to talk button (that's the button on the left side of the radio that is bigger than the other two for those of you who haven't checked out all the radio functions yet, and may or may not be visually impaired, and haven't used a radio of this sort before. (Hey, I'm just being thorough here, don't get your panties in a bunch). at the same time that you turn on the radio.  This will put the radio into programming mode, (or firmware mode as I said before.
After the upload is complete, the light on the top will stop flashing, and the radio will reboot.  For screen reader users, just tab once after you hit the open button when the upload starts, and it will put you into the field where it will eventually show you the message that the radio has rebooted. (I'm assuming the visually abled will already know/be able to see this, but most likely, they won't be using this firmware anyhow, because it doesn't have very many bells and whistles, and it's loaded with talking things, which most sighted folks don't seem to like very much).
After that, you can pull the programming cable, and start using the radio assuming it's done booting.  You can also turn off and back on to verify all is working as it should, since you can't hear the boot process while the radio is plugged into the computer.
So, once all that's done, we can then get to work using the radio.

But not before we go over what's included in the archive. :)

1: You'll find the firmware.bin file, this is the one you'll upload to the radio to enable all the accessibility goodness.
2: A copy of the publisher firmware, just in case something goes sideways, and you want to restore the radio to it's previous state, this file is called: k5_v2.01.31_publish.bin.
3: this readme.txt file with all the information you'll need to work with this firmware, and of course, the documentation you're probably reading now.
4: A copy of the k5prog-win executable, which is the program you'll use to flash this shiny new firmware onto your radio.
5: And of course, the license file that makes all of this possible.  (it uses an apache 2.0 license for those of you who are already familiar with such things.

You will be able to find the source code for this on my github site once I get all of this uploaded there.  I'm not great with github, so I haven't done the necessary things to have this code be an official fork of the original code just yet, but I'll get there, and in the mean time, I'll have a gzipped tar ball of the source available on my softcon.com site in the files area for those who want a copy to download it.  Do keep in mind, I'm an intermediate C/C++ programmer at best, so my coding is nothing to write home about, but it does seem to do the job, so please let me know when you encounter problems.  I'll do my best to fix them.  No guarantees though, since C/C++ is not my language of choice, so I spend a good amount of time avoiding it when possible.

And, now on to the firmware and it's use.

First, let's go over the menus.
The menus are and their changes are as follows:
****
1: Frequency Step
2: Power,
3: RxDCS,
Rx CTCS,
4: TxDCS
Tx CTCS
5: TX_OFFSET_FREQUENCY_DIRECTION
6: TX_OFFSET_FREQUENCY
7: CHANNEL_BANDWIDTH
8: SCRAMBLER
9: BUSY_LOCKOUT
11: Compnd
12: AM Demodulation
13: ScAdd1
14: ScAdd2
15: Save MEMORY CHANNEL,
16: DELETE_CHANNEL,
17: Channel Name
18: SList
19: SList1
20: SList2
21: Scan Reverse
22: F1Shrt
23: F1Long
24: F2Shrt
25: F2Long
26: Menu Long
27: Auto Lock
28: TRANSMIT_OVER_TIME
29: Battery Saver
30: Mic
31: MicBar
32: Change Display
33: POnMsg
34: Battery Txt
35: BackLight
36: BackLight Min
37: BackLight Max
38: BltTRX
39: BEEP_PROMPT,
40: VOICE_PROMPT,
41: Roger
42: STEP
43: RP STE
44: 1 Call
45: UPCode
46: DWCode
47: PTT ID
48: D ST
49: D Prel
50: D Live
51:AM Fix
52: Battery Voltage
58: DUAL_STANDBY,
59: SQUELCH,
	// hidden menu items from here on
	// enabled if pressing both the PTT and upper side button at power-on
60: F Lock
61: Tx 200
62: Tx 350
63: Tx 500
64: 350 En
65: ScraEn
66: Battery Calibration
67: Battery Type
68: Reset
*****

** just for reference**
For some reason, there's two menu items that don't behave when you're going through the menus.  Item 21 is spoken as item 22, as is the actual item 22, so just be aware of that.  Same thing happens to menu item 34, for some reason it's spoken as item 33 as is the actual item 33. Beats me why this happens, but if I find a fix, I'll of course include it in a future release.

The step menu:
Here I gave the various steps their numeric equivalents (minus the decimal points, since there is no period/point in the speech files).
This makes it a bit confusing if you don't know what's going on, so be careful about choosing your step size. 
The steps show up in the menu in this order.
0.01 KHZ
0.05KHZ
0.1KHZ
0.25KHZ
0.50KHZ
1KHZ
1.25KHZ
2.50KHZ
5.0KHZ
6.25KHZ
8.33KHZ
9KHZ
10KHZ
12.5KHZ
15KHZ
20KHZ
25KHZ
30KHZ
50KHZ
100KHZ
125KHZ
200KHZ
250KHZ
500KHZ

The power menu.
The options in this menu are fairly straightforward.  Low, Medium, and High.  But, because none of these options appear in the voice snippets, I opted to number these as 1, 2 and 3 respectively.  You can also change the power levels by doing a long press on the keypad number 6.

DCS/CTCSS receive:
Both the receive and transmit DCS values are represented here, which is why each one shows up twice.  First time is receive, second time is transmit, but the only option that speaks is the one saying "off".  The others are not accessible at this time.

DCS/CTCSS transmit:
Both the receive and transmit CTCS values are represented here, which is why each one shows up twice.  First time is receive, second time is transmit, There are 50 options to choose from, and all of these options speak, so setting the tone needed for the repeater entries is working now.

SFT_D:
Offset direction
This menu has three values, off, plus, and minus.  Since most other menus have on/off options, and this one has plus and minus, I took a different approach with this menu.
For the off option, the speech does say "off".
For the plus value, the radio will play a double beep tone.
For the minus value, the radio will play a tripple beep tone.
These tones are at different frequencies, and they are use elsewhere in the radio code, so you might recognize them already by the time you get around to adjusting this menu option.

Offset frequency:
At the moment, this option is a bit tricky, but it does talk, but just be aware that trying to adjust the values by using the arrow keys doesn't work very well, and the entry of values appears to not be working at first, but once you get enough zeros entered, you'll find it saying the proper number.  I'm still working on this option, so hopefully there will be better access in a future release of the firmware.

Wide/Narrow bandwidth:
This might seem a bit counterintuitive, but I went with the order in which they show up in the menu.
Wide is represented by a 1, and narrow is represented by a 2, so selecting either of these options will set the bandwidth accordingly (I'm assuming 12.5KHZ and 25KHZ as on most other radios.

Scramble:
The scrambler menu really has no place on an FCC approved radio, since amateur communications are supposed to be in the clear, but nonetheless, I've went ahead and made this menu accessible as well.  The only caveat to this one is the fact that there is no thousand voice snippet, so the 3,000 menu options speaks as 30 hundred.  I'm sure folks will be able to figure out what that means, but I suspect many will find it a bit jarring to be going along, 28 hundred, 29 hundred, 30 hundred, 31 hundred, ... (sorry, nothing I can do about that one).

Busy lockout:
This has just the on and off selections.  This determines whether or not you're able to transmit if another signal is already coming through on the tx channel.

compound:
not accessible at this time.

demodulation:
This has 3 options: 
1 is FM (Frequency Modulation the default), 2 AM (Amplitude Modulation), and 3 is USB (upper Side Band)
This setting can also be set using a long press on the keypad number 7.

SCADD1:
not accessible at this time.

SCADD2:
Not accessible at this time.

Memory Channel:
This option allows you to select a channel to write the current values to then it will save it into the channel you select, so they're there the next time you wish to use them.
How this works is you first need to be in frequency mode, then set all the items you need, such as frequency, offset and offset direction.  After you get everything configured the way you want, then you can enter the menus, select memory channel, then scroll up/down until you find the channel you want to add the current settings to.  After you find the channel number you want to assign the values to, press the menu button and your settings will be saved.  Press the menu key a second time to bypass the data entry for the name displayed when the channel shows up on the screen, and you're done.  You can let the menu time out, or you can press the cancel key to get out of the menus.

Delete Channel:
This menu option works nearly identical to the memory channel adding menu option.  Simply scroll up/down until you find the memory channel you wish to delete, then press the menu key to perform the delete. That's it, the channel is removed, and it's available again for new entries.

Channel Name:
Not accessible at this time.

Slist:
Not accessible at this time.

Slist2:
Not accessible at this time.

Slist3:
Not accessible at this time.

SCNREV:
There are three options here.  1: timeout, 2: Carrier, and 3: stop. Since I'm not familiar with this menu option, I have no idea what these options do/control.

f1 short monitor:
not accessible at this time.

f1 long monitor:
not accessible at this time.

f2 short monitor:
not accessible at this time.

f2 long monitor:
not accessible at this time.

f_Menu monitor:
not accessible at this time.

autolock:
The two options in this menu are supposed to be off, and auto, but since there is no voice snippet for auto, I set the second option here to lock.

TOT:
This is the transmit over time menu.
This limits how long you can transmit with a single press of the push to talk button.  It prevents overheating, among other things.
In this menu, I couldn't put units of measure (seconds, minutes), so to clear the confusion, the first option is 30 seconds, all the rest of the options are in minutes.

Save:
The options in this menu are ratios, it should read 1:1, 1:2 and so on, but again, nothing like that is in voice snippets, so besides the off option, I cheated and put the numbers 121 through 124 as the options here, so that the speech says 1 2 1, 1 2 2 and so on.
This menu is to set the amount of time the radio spends sleeping, as opposed to doing other things (like scanning I suspect).

The mic menu, :
(not accessible at this time)

The Mike bar menu:
Not accessible at this time.

SCREN:
off and on are the options in this menu, and they control whether the scramble option is on or off.  (see menu option 9 to set the scramble code used)

Channel Display:
options in this menu are listed as 1 through 4.  The menu options are:
1: Frequency
2: Channel number
3: name
4: name and frequency

PONMSG:
Power on Message, the options are Full, Message, and Voltage, and are selectable with the options 1, 2 or 3.

Battery Txt
This menu determins what's shown for the battery on the display.  The options are:
none, voltage, or percent.
I've simply numbered the options 1, 2, and 3.
I'm still working on making the percent values speak, but you'll probably want to select number 3 in this menu, so you can get battery percent numbers when I get that part working.

ABR (backlight duration):
The first option is off, the next three options are in seconds (5, 10, 20), the next 3 are in minutes (1, 2, 4) and the last one is always on (spoken as on)
 
BLMIN:
Not accessible at this time.

BLMAX:
Not accessible at this time.

BLTTRX:
Not accessible at this time.

Beep Prompts:
Only two options here, on and off, both speak of course.  Just a note, if you turn these off, the radio will not beep when it boots, and you won't get the beeps when you long press keys.

Voice Prompts:
There's supposed to be three options here, off, chinese, and english.  The only one that has a voice snippet is (you guessed it) off.  So, for the other two, I used nothing for chinese, so that it doesn't say anything, and for english,I used the word "end" This is close enough to eng that I figured it could pass muster.

ROGER:
Three options in this menu as well, Off, Roger, and MDC.  The firstoption is spoken as (as always), off.  The next two are spoken as 1 for roger, and 2 for MDC.  I'm fairly certain this puts up different tones when transmitting at the end of transmission, but I've not tested this to verify.

STE:
The first option (off) speaks, all other options are not accessible at this time.

RPSTE:
Not accessible at this time.

1-call:
not accessible at this time.

ANICODE:
Not accessible at this time.

UpCode:
Not accessible at this time.

DownCode:
Not accessible at this time.

PTTID:
Not accessible at this time.

D ST:
Not accessible at this time.

D RESP:
Not accessible at this time.

D Hold:
Not accessible at this time.

D PREL:
Not accessible at this time.

D DECD:
Not accessible at this time.

D List:
Not accessible at this time.

D Live:
Just your standard on/off options, both speak. (no idea what this menu does).

AM FIX:
again, just your standard on/off options, both speak. (this menu turns on the extra processing to make the AM signal processing better).

Battery Voltage:
There has been some work to make this accessible, but it doesn't work yet, so the output is unreliable.  On my radio, it just keeps repeating the number 7.  (still working on this one).

rx Mode:
Options in this menu are as follows:
Off,
RX,
TX,
RX/TX
Off speaks as normal, then options 1, 2, and 3 are the rx, tx, and rx/tx respectively.

***EXTRA MENUS*** (these options are accessed by holding the f1 button along with the PTT button when turning on the radio.)
Reset:
Options are 1 and 2 for VFO and ALL.

Frequency lock:
There are 8 options in this menu (well, printed menus show 9, but we're only concerned with 8 of them, since we're assuming if you're selecting the menu, you already know what you're doing, so no need to remind you to read the manual).
The options are as follows:
1: 	"DEFAULT+\n137-174\n400-470",
2: 	"FCC HAM\n144-148\n420-450\n", *2
3: 	"CE HAM\n144-146\n430-440",
4: 	"GB HAM\n144-148\n430-440",
5: 	"137-174\n400-430",
6: 	"137-174\n400-438",
7: 	"DISABLE\nALL",
8: 	"UNLOCK\nALL",

*****
Just for reference, there's actually more frequencies handled by the FCC lock option, but I didn't add anything beyond the default frequencies to the menus, so only 2 are listed. All of the frequencies unlocked by the FCC option are all of those allowed by amateurs in the U.S. as follows: 
18.068 - 18.168 MHZ //17Meter band
21.00 - 21.45 MHZ //15Meter band 
24.89 - 24.99 MHZ  //12Meter band
28.00 - 29.70 //10Meter band
50 - 54 MHZ //6Meter band
144 - 148 MHZ //2Meter band
222 - 225 MHZ   //1.25 Meter band
420 450 MHZ    //70 CM band
902 - 928 MHZ  //33 CM band
1.24 - 1.3 GHZ  //23 CM band
The 2-meter and 70-centimeter bands are the only ones that were there by default, so be advised that broadcasting on the other frequencies will probably not work well, or produce plenty of spurious emissions.
*****

TX200:
just your standard two on/off options.

TX350:
just your standard two on/off options.

TX-500:
just your standard two on/off options.

TX-350EN:
just your standard two on/off options.

SCREN:
Determines if the scramble function is enabled or not (basically, just your standard on/off options).

Battery calibration:
Not accessible at this time.

Battery Type:
This menu is accessible, you can select whether you have a 1600 MAH battery, or a 2200 MAH battery.  Obviously, only the numbers are spoken, as there's no MAH voice snippet.

The squeltch menu, :
Options 0 through 9.  0 is the squelch is off entirely, 1-9 are varying degrees of suppressing background noise.  Interestingly enough, mine was set to 6 by default.  That seems a bit high to me.

Now, on to the key functions.

The radio has both short and long presses of buttons to make things happen.  The keypad behaves as follows:
Menu:
Short press brings up the menus, to configure the radio.
Long press speaks the current frequency 
up/down arrows short press move through the menus when in menu mode, and change your current frequency by the amount of your step value when outside of menus.
The exit key short press cancels the current operation if you're in a menu or input box of any kind, otherwise it does nothing.

Keypad 1:
short press enters the number 1
long press jumps to the next band in sequence
Keypad 2:
short press enters the number 2
long press swaps the rx and tx frequencies
Keypad 3:
short press enters the number 3
Long press Switches between VFO and Memory channel Mode
Keypad Function:
short press does nothing by itself, but is used in combination with other keys to activate some functions
long press starts scan
Keypad 4:
short press enters number 4
long press Start Fast Copy One Channel
Keypad 5:
short press enters number 5
long press switches to frequency mode
Keypad 6:
short press enters number 6
long press changes power level
Keypad 0:
short press enters number 0
long press enters fm radio mode
Keypad 7:
short press enters number 7
long press changes radio demodulation (FM, AM and USB) (and if raw demodulators are turned on, byte and raw as well.) (these are not turned on with the version I release)
Keypad 8:
short press enters the number 8
long press reverses frequencies
Keypad 9:
short press enters number 9
long press switches to one key emergency calling
Keypad number:
short press does nothing.
Long press locks and unlocks the keypad.

Miscellaneous information:
When you turn on the radio, it beeps to let you know it's booting properly (well, that's my story, and I'm sticking to it).
It will then tell you what mode you're in, channel mode, or frequency mode.
If in frequency mode, it will speak the current frequency
If in channel mode, it will speak the current channel number.

Miscellaneous items:
* I'm pretty sure I can make entering channel information accessible, but that will take a bit of doing, and I'm about to loose internet access for a few weeks, so figured I'd get this uploaded before that happened.
* If channel information is able to be entered from the keypad, be advised, it won't be a very intuitive process, but it will work, although once it's entered, you won't be able to read the channel names, just the frequencies and channel numbers, which of course is one of the settings in that menu, so you might want to select that one now, before we get to that point, so you'll be prepared when the new version adds that capability.
* I'm fully intending to make the FM radio on this rig accessible as well, I've already done some of the preliminary testing to verify it will work, so I expect that will be in the next release, (or perhaps the one after that).  Frequencies and channel numbers will be able to be spoken.  FM radio is considerably easier to work with than Ham radio is, because of it's limited functionality as far as accessing frequencies/channels goes, so it should be a relatively easy fix to make the FM Radio completely accessible as well.

At the moment, that's all there is, but hopefully, this will give you enough to work with, and you can get on the air using this firmware.
As mentioned above, corrections, suggestions, patches, and general advice are welcome. 