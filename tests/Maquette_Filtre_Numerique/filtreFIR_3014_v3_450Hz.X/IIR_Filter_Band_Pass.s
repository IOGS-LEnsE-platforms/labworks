; ..............................................................................
;    File   IIR_Filter.s
; ..............................................................................

		.equ IIR_FilterNumSections, 3

; ..............................................................................
;
; Allocate and initialize filter coefficients
;
; These coefficients have been designed for use in the Transpose filter only

		.section .xdata

IIR_FilterCoefs:
.hword	0x013C	; b( 1,0)/2
.hword	0x0000	; b( 1,1)/2
.hword	0x7C4A	; a( 1,1)/2
.hword	0xFEC4	; b( 1,2)/2
.hword	0xC279	; a( 1,2)/2
.hword	0x00E6	; b( 2,0)/2
.hword	0x0000	; b( 2,1)/2
.hword	0x7D04	; a( 2,1)/2
.hword	0xFF1A	; b( 2,2)/2
.hword	0xC166	; a( 2,2)/2
.hword	0x01B9	; b( 3,0)/2
.hword	0x0000	; b( 3,1)/2
.hword	0x7DEB	; a( 3,1)/2
.hword	0xFE47	; b( 3,2)/2
.hword	0xC11A	; a( 3,2)/2

; ..............................................................................
; Allocate states buffers in (uninitialized) Y data space

		.section .ybss,  "b"

IIR_FilterStates1:
		.space IIR_FilterNumSections*2

IIR_FilterStates2:
		.space IIR_FilterNumSections*2

; ..............................................................................
; Allocate and intialize filter structure

		.section .data
		.global _IIR_FilterFilter

_IIR_FilterFilter:
.hword IIR_FilterNumSections-1
.hword IIR_FilterCoefs
.hword 0xFF00
.hword IIR_FilterStates1
.hword IIR_FilterStates2
.hword 0x0000

; ..............................................................................
; Sample assembly language calling program
;  The following declarations can be cut and pasted as needed into a program
;		.extern	_IIRTransposeFilterInit
;		.extern	_BlockIIRTransposeFilter
;		.extern	_IIR_FilterFilter
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
;		mov	#_IIR_FilterFilter, W0	; Initalize W0 to filter structure
;		call	_IIRTransposeFilterInit	; call this function once
;
; The next 4 instructions are required prior to each subroutine call
; to _BlockIIRTransposeFilter
;		mov	#_IIR_FilterFilter, W0	; Initalize W0 to filter structure
;		mov	#input, W1	; Initalize W1 to input buffer 
;		mov	#output, W2	; Initalize W2 to output buffer
;		mov	#20, W3	; Initialize W3 with number of required output samples
;		call	_BlockIIRTransposeFilter	; call as many times as needed
