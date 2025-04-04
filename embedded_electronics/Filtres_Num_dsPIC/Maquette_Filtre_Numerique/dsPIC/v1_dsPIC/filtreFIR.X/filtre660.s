; ..............................................................................
;    File   filtre660.s
; ..............................................................................

		.equ filtre660NumTaps, 17

; ..............................................................................
; Allocate and initialize filter taps

		.section .filtre660const, "x"
		.align 64

filtre660Taps:
.hword 	0x0414,	0x047F,	0xFFD9,	0xF986,	0xF813,	0x0028,	0x1017,	0x1FF3,	0x2693
.hword 	0x1FF3,	0x1017,	0x0028,	0xF813,	0xF986,	0xFFD9,	0x047F,	0x0414

; ..............................................................................
; Allocate delay line in (uninitialized) Y data space

		.section .ybss,  "b"
		.align 64

filtre660Delay:
		.space filtre660NumTaps*2

; ..............................................................................
; Allocate and intialize filter structure

		.section .data
		.global _filtre660Filter

_filtre660Filter:
.hword filtre660NumTaps
.hword psvoffset(filtre660Taps)
.hword psvoffset(filtre660Taps)+filtre660NumTaps*2-1
.hword psvpage(filtre660Taps)
.hword filtre660Delay
.hword filtre660Delay+filtre660NumTaps*2-1
.hword filtre660Delay

; ..............................................................................
; ..............................................................................
; Sample assembly language calling program
;  The following declarations can be cut and pasted as needed into a program
;		.extern	_FIRFilterInit
;		.extern	_BlockFIRFilter
;		.extern	_filtre660Filter
;
;		.section	.bss
;
;	 The input and output buffers can be made any desired size
;	   the value 40 is just an example - however, one must ensure
;	   that the output buffer is at least as long as the number of samples
;	   to be filtered (parameter 4)
;input:		.space	40
;output:	.space	40
;		.text
;
;
;  This code can be copied and pasted as needed into a program
;
;
; Set up pointers to access input samples, filter taps, delay line and
; output samples.
;		mov	#_filtre660Filter, W0	; Initalize W0 to filter structure
;		call	_FIRFilterInit	; call this function once
;
; The next 4 instructions are required prior to each subroutine call
; to _BlockFIRFilter
;		mov	#_filtre660Filter, W0	; Initalize W0 to filter structure
;		mov	#input, W1	; Initalize W1 to input buffer 
;		mov	#output, W2	; Initalize W2 to output buffer
;		mov	#20, W3	; Initialize W3 with number of required output samples
;		call	_BlockFIRFilter	; call as many times as needed
