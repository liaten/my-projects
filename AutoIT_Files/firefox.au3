If FileExists("C:\Program Files\Mozilla Firefox\firefox.exe") Then
    $prompt = msgbox(4129, "Continue?", "Open gmail.com")
	Switch $prompt
	Case "1"
	   Shellexecute('https://gmail.com')

   Case "2"
	  Exit
    EndSwitch
Else
    MsgBox(4096, "ERROR","Firefox does not exist")
 EndIf