loadAPI(18);

// Remove this if you want to be able to use deprecated methods without causing script to stop.
// This is useful during development.
host.setShouldFailOnDeprecatedUse(true);

host.defineController("Vermoot", "4faders", "0.1", "07c01bd1-a0ae-49ce-b597-739d72286d77", "Vermoot");

host.defineMidiPorts(1, 1);

if      (host.platformIsWindows()) {}
else if (host.platformIsMac())     {}
else if (host.platformIsLinux())   { [ "4faders MIDI 1", "4faders MIDI 1" ]; }

var CC = {
	CYCLE:  0x2E,
	STOP:   0x2A,
	PLAY:   0x29,
	REC:    0x2D,
	REW:    0x2B,
	FF:     0x2C,
	FADER1: 0x00,
	FADER4: 0x03,
	KNOB1:  0x10,
	KNOB8:  0x17,
};

// var transport = null;
function init() {
   transport = host.createTransport();
   var inputPort = host.getMidiInPort(0);
   inputPort.setMidiCallback(onMidi0);
   inputPort.setSysexCallback(onSysex0);

   // TODO: Perform further initialization here.
   println("4faders initialized!");
}

// Called when a short MIDI message is received on MIDI input port 0.
function onMidi0(status, data1, data2) {
   printMidi(status, data1, data2);
   if (isNoteOn(status)) {
      switch(data1) {
         case CC.CYCLE:
            transport.isArrangerLoopEnabled().toggle();
            break;
         case CC.STOP:
            transport.stop();
            break;
         case CC.PLAY: // TODO toggle but stay where you are ?
            transport.togglePlay();
            break;
         case CC.REC:
            transport.record();
            break;
      }
   }
}

function onSysex0(data) {
   // TODO: Handle sysex messages here.
}

function flush() {
   // TODO: Flush any output to your controller here.
}

function exit() {

}
