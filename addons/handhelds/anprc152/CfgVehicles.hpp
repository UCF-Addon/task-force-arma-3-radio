class Item_TFAR_anprc152: Item_Base_F {
    scope = PUBLIC;
    scopeCurator = PUBLIC;
    displayName = "AN/PRC-152";
    author = "Nkey";
    vehicleClass = "Items";
    class TransportItems {
        MACRO_ADDITEM(TFAR_anprc152,1);
    };
    editorCategory = "TFAR";
    class Attributes {//#TODO move Attributes into base class for all Radio Vehicles
    // Attribute class, can be anything
        class staticRadioFrequency {//#TODO Frequencies! Array!!!
            //--- Mandatory properties
            displayName = "Frequency"; // Name assigned to UI control class Title
            tooltip = "The static Frequency for this radio"; // Tooltip assigned to UI control class Title
            property = "staticRadioFrequency"; // Unique config property name saved in SQM
            control = "Edit"; // UI control base class displayed in Edit Attributes window, points to Cfg3DEN >> Attributes

            // Expression called when applying the attribute in Eden and at the scenario start
            // The expression is called twice - first for data validation, and second for actual saving
            // Entity is passed as _this, value is passed as _value
            // %s is replaced by attribute config name. It can be used only once in the expression
            // In MP scenario, the expression is called only on server.
            expression = "_this setVariable ['%s',_value];";//#TODO call function that sents that variable to the radio in the container

            // Expression called when custom property is undefined yet (i.e., when setting the attribute for the first time)
            // Entity is passed as _this
            // Returned value is the default value
            // Used when no value is returned, or when it's of other type than NUMBER, STRING or ARRAY
            // Custom attributes of logic entities (e.g., modules) are saved always, even when they have default value
            defaultValue = "[]";

            //--- Optional properties
            validate = "none"; // Validate the value before saving. Can be "none", "expression", "condition", "number" or "variable"
            condition = "objectHasInventoryCargo"; // Condition for attribute to appear (see the table below)
            typeName = "STRING"; // Defines data type of saved value, can be STRING, NUMBER or BOOL. Used only when control is "Combo", "Edit" or their variants
        };
//#TODO Current Channel, Speaker config,volume


    };
};
HIDDEN_CLASS(Item_tf_anprc152 : Item_TFAR_anprc152); //#Deprecated dummy class for backwards compat
