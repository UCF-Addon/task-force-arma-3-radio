#include "script_component.hpp"

/*
    Name: TFAR_static_radios_fnc_instanciatedRadio

    Author(s):
        Dedmen

    Description:
        Instanciates Radio if it isn't already.
        Internal use only!

    Parameters:
        OBJECT - The weaponholder containing the Radio

    Returns:
        STRING - classname of instanciate Radio

    Example:
        _this call TFAR_static_radios_fnc_instanciatedRadio;
*/
params ["_radioContainer"];


_radioClass = (typeOf ((getItemCargo _radioContainer) select 0) select 0);
diag_log ["TFAR_static_radios_fnc_instanciatedRadio",_this,_radioClass];
if !(_radioClass call TFAR_fnc_isPrototypeRadio) exitWith {_radioClass};

([_radioClass] call TFAR_fnc_instanciateRadios select 0)
