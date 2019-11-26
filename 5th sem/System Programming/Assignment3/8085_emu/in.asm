		mvi a,00
		mvi b,01
		mvi c,05
		lxi h,3000 ; abbababab

loop:	add m ;tretetetet
		inx h ;
abc:	dcr c
def:	jnz loop
		aaa
		adi 08
		mvi c,0A
		aaa
		hlt

aaa 	macro
		add c
		mend