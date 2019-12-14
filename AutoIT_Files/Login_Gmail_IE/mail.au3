#include <IE.au3>

$sEmail = 'login'
$sPassword = 'passw'

$oIE = _IECreate('https://accounts.google.com/signin/v2/identifier?continue=https%3A%2F%2Fmail.google.com%2Fmail%2F&service=mail&sacu=1&rip=1&flowName=GlifWebSignIn&flowEntry=ServiceLogin')
GMailSubmitFormElement($oIE,'identifier',$sEmail)
GMailSubmitFormElement($oIE,'password',$sPassword)

Sleep(10000)

_IEQuit($oIE)

Func GMailSubmitFormElement($oIE,$sElement,$sValue,$iTimeout=10, $iDelay=1)
    $Timer = TimerInit()
    Do
        $oForm = _IEFormGetCollection($oIE,0)
        $oElement = _IEFormElementGetObjByName($oForm,$sElement)
        Sleep($iDelay * 1000)
    Until IsObj($oElement) Or TimerDiff($Timer) >= $iTimeout * 1000
    _IEFormElementSetValue($oElement,$sValue)
    $oViewContainer = _IEGetObjById($oIE,'view_container')
    $oSpans = _IETagNameGetCollection($oViewContainer,'span')
    For $oSpan In $oSpans
        If $oSpan.innerHTML = 'Next' Then
            _IEAction($oSpan,'click')
            ExitLoop
        EndIf
    Next
EndFunc