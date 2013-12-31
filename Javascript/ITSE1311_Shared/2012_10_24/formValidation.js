    // formValidation.js
    //
    // You may freely use this script for all educational, commercial, or
    // non-commercial purposes.  Your use of this script is at your own
    // risk.  No warranty or guarantee is expressed or implied.
    
    //Here is a utility function that returns true if a string contains only
    //whitespace characters:
    function isblank(s)
    {
      for (var I = 0; I < s.length; I++)
      {
        var c = s.charAt(I);
        if ((c != ' ') && (c != '\n') && (c != '\t')) return false;
      }
      return true;
    }
    
    //This function validates an e-mail address for some simple requirements:
    //1 or more non-numeric characters followed by zero or more characters 
    //(including underscores), followed by "@", followed by 1 or more 
    //characters followed by zero or more characters (including underscores), 
    //followed by ".", followed by 1 or more characters.
    function validateEmail(emailaddress)
    {
      var retValue = true;
      
      var mailRE = /^([a-zA-Z0-9_\.\-])+\@(([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9]{2,4})+$/;
      retValue = mailRE.test(emailaddress);
      
      return retValue;
    }
    
    //This function validates a phone number
    function validatePhoneNumber(phonenum)
    {
      var retValue = true;
      
      var phoneRE = /^((\+\d{1,3}(-| )?\(?\d\)?(-| )?\d{1,5})|(\(?\d{2,6}\)?))(-| )?(\d{3,4})(-| )?(\d{4})(( x| ext)\d{1,5}){0,1}$/;
      retValue = phoneRE.test(phonenum);
      
      return retValue;
    }
    
    //This function validates a Zip code
    function validateZipcode(zipcode)
    {
      var retValue = true;
      
      var zipRE = /^\d{5}-?(\d{4})?$/;
      retValue = zipRE.test(zipcode);
      
      return retValue;
    }
    
    //This function validates a password for strength
    function validatePassword(pwd, strength)
    {
      var retValue;
      var strongRegex = new RegExp("^(?=.{8,})(?=.*[A-Z])(?=.*[a-z])(?=.*[0-9])(?=.*\\W).*$", "g");
      var mediumRegex = new RegExp("^(?=.{7,})(((?=.*[A-Z])(?=.*[a-z]))|((?=.*[A-Z])(?=.*[0-9]))|((?=.*[a-z])(?=.*[0-9]))).*$", "g");
      var enoughRegex = new RegExp("(?=.{6,}).*", "g");
      
      if ((strongRegex.test(pwd)) && ((strength == "strong") || (strength == "medium") ||
          (strength == "weak")))
      {
        retValue = true;
      }
      else if ((mediumRegex.test(pwd)) && ((strength == "medium") || (strength == "weak")))
      {
        retValue = true;
      }
      else if ((enoughRegex.test(pwd)) && (strength == "weak"))
      { 
        retValue = true;
      }
      else
      {
        retValue = false;
      }
      
      return retValue;
    }
    
    //Here is the function that performs the form verification. It will be invoked
    //from the onSubmit() event handler.  The handler should return whatever value
    //this function returns.
    function verify(f)
    {
      var msg;
      var empty_fields = "";
      var errors = "";
      var empty_count = 0;
      var number_count = 0;
      var e;
      var o;
      var is_empty;
  
      //Loop through the elements of the form, looking for all
      //text, textarea, select, password, and file elements that have a required="true"
      //property defined.
      //
      //NOTE: text, textarea, file, password, and select elements must define the "required"
      //property in the onsubmit attribute of the <form> tag.
      //
      //Also look for all radio button and checkbox elements that have a
      //title="required" property defined.
      //
      //NOTE: Radio and checkbox elements
      //must define a title="required" attribute in the first input tag of each set.
      //The radio and checkbox elements that are required must include the
      //title="required" attribute in ONLY ONE (the first) of the elements in the set.
      //
      //NOTE: You can also add a property "labelname" to non-radio and non-checkbox
      //fields to use the "labelname" value in the error messages instead of the
      //field's "name" attribute value.  You can also include underscores (_) in
      //the field's "name" attribute.  The underscores will be replaced with
      //spaces in the error messages, as the field's name.
      //
      //NOTE: For radio and checkbox fields, you can include underscores (_) in
      //the field's "name" attribute.  The underscores will be replaced with
      //spaces in the error messages, as the field's name.
      //
      //Check for fields that are empty and make a list of them.  Use this list of
      //empty fields to report the required empty fields to the user.
      //
      //If any of these elements have a "min", "max", or "numeric" property defined,
      //then verify that they are numbers and that they are in the right range.
      //
      //If any fields have an "emailfield" property defined, verify for an
      //e-mail address pattern.
      //
      //If any fields have a "phonenumberfield" property defined, verify for a
      //phone number pattern.
      //
      //If any fields have a "zipcodefield" property defined, verify for a
      //Zip code pattern.
      //
      //If any fields have a "passwordfield" property defined, verify for a 
      //password of the required strength.  If you use the "passwordfield" 
      //property, you can also use a "passwordStrength" property.  It defaults
      //to strong.  The possible explicit values are weak, medium, and strong.
      //
      //Put together error messages for fields that are wrong.

      for (var i = 0; i < f.elements.length; i++)
      {
        e = f.elements[i];
      
        if ((e.type == "text") || (e.type == "textarea") || (e.type == "file") || (e.type == "password"))
        {
          //Check if the field is empty
          if ((e.value == null) || (e.value == "") || isblank(e.value))
          {
          	is_empty = true;
          	if (e.required == true)
          	{
              if (e.labelname != null)
              {
                empty_fields += "\n          " + e.labelname;
              }
              else
              {
                empty_fields += "\n          " + e.name.replace(/_/g," ");
              }
              empty_count++;
              continue;
          	}
          }
          else
          {
          	is_empty = false;
          }
          
          //Now check for fields that are supposed to be numeric.
          if (!is_empty && ((e.numeric == true) || (!isNaN(parseInt(e.min))) || (!isNaN(parseInt(e.max)))))
          {
            var v = parseFloat(e.value);
            if (isNaN(v) ||
               ((!isNaN(parseInt(e.min))) && (v < parseInt(e.min))) ||
               ((!isNaN(parseInt(e.max))) && (v > parseInt(e.max))))
            {
              if (e.labelname != null)
              {
                errors += " - " + e.labelname + " must be a number";
              }
              else
              {
                errors += " - " + e.name.replace(/_/g," ") + " must be a number";
              }
              if (!isNaN(parseInt(e.min)))
                errors += " that is greater than or equal to " + e.min;
              if ((!isNaN(parseInt(e.max))) && (!isNaN(parseInt(e.min))))
                errors += " and less than or equal to " + e.max;
              else if (!isNaN(parseInt(e.max)))
                errors += " that is less than " + e.max;
              errors += ".\n";
              number_count++;
            }
          }
          
          //Now do a simple pattern test for e-mail addresses:
          if (!is_empty && e.emailfield == true)
          {
            var validEmail = validateEmail(e.value);
            
            if (!validEmail)
            {
              if (e.labelname != null)
              {
                errors += " - " + e.labelname + " must be a valid e-mail address.";
              }
              else
              {
                errors += " - " + e.name.replace(/_/g," ") + " must be a valid e-mail address.";
              }
              errors += "\n";
            }
          }
          
          //Now do a simple pattern test for phone number:
          if (!is_empty && e.phonenumberfield == true)
          {
            var validPhone = validatePhoneNumber(e.value);
            
            if (!validPhone)
            {
              if (e.labelname != null)
              {
                errors += " - " + e.labelname + " must be a valid phone number.";
              }
              else
              {
                errors += " - " + e.name.replace(/_/g," ") + " must be a valid phone number.";
              }
              errors += "\n";
            }
          }
          
          //Now do a simple pattern test for Zip code:
          if (!is_empty && e.zipcodefield == true)
          {
            var validZip = validateZipcode(e.value);
            
            if (!validZip)
            {
              if (e.labelname != null)
              {
                errors += " - " + e.labelname + " must be a valid Zip code.";
              }
              else
              {
                errors += " - " + e.name.replace(/_/g," ") + " must be a valid Zip code.";
              }
              errors += "\n";
            }
          }
          
          //Now do a pattern test for password strength:
          if (!is_empty && ((e.type == "password") && (e.passwordfield == true)))
          {
            var strengthIndicator = "";
            
            if ((e.passwordStrength) && (e.passwordStrength != null) && ((e.passwordStrength == "strong") ||
                (e.passwordStrength == "medium") || (e.passwordStrength == "weak")))
            {
              strengthIndicator = e.passwordStrength;
            }
            else
            {
              strengthIndicator = "strong";  // default to strong
            }
            
            var validPassword = validatePassword(e.value, strengthIndicator);
            
            if (!validPassword)
            {
              if (e.labelname != null)
              {
                errors += " - " + e.labelname + " must be a valid " + strengthIndicator + " password";
              }
              else
              {
                errors += " - " + e.name.replace(/_/g," ") + " must be a valid " + strengthIndicator + " password";
              }
              switch (e.passwordStrength)
              {
                case "strong":
                  errors += ", with at least 8 characters including upper- and lower-case letters, at least 1 numeric digit, and at least 1 special character."
                  break;
                case "medium":
                  errors += ", with at least 7 characters including upper- and lower-case letters, and at least 1 numeric digit."
                  break;
                case "weak":
                  errors += ", with at least 6 characters."
                  break;
                default:
                  errors += "."
              }
              errors += "\n";
            }
          }
        }
        
        if (((e.type == "select-one") || (e.type == "select-multiple")) && (e.required == true))
        {
          var itemSelected = false;
          
          for (var j = 0; j < e.options.length; j++)
          {
            o = e.options[j];
            if (o.value != "")
            {
              if (o.selected == true)
              {
                itemSelected = true;
              }
            }
          }
          
          if (itemSelected == false)
          {
            if (e.labelname != null)
            {
              empty_fields += "\n          " + e.labelname;
            }
            else
            {
              empty_fields += "\n          " + e.name.replace(/_/g," ");
            }
            empty_count++;
          }
        }
        
        if (((e.type == "radio") || (e.type == "checkbox")) && (e.title == "required"))
        {
          var itemChecked = false;
          
          for (var itemNum = 0; itemNum < f[e.name].length; itemNum++)
          {
            if (f[e.name][itemNum].checked == true)
            {
              itemChecked = true;
              break;
            }
          }
          
          if (itemChecked == false)
          {
            if (e.labelname != null)
            {
              empty_fields += "\n          " + e.labelname;
            }
            else
            {
              empty_fields += "\n          " + e.name.replace(/_/g," ");
            }
            empty_count++;
          }
        }
      }  
      
      //Now, if there were any errors, display the messages, and
      //return false to prevent the form from being submitted.
      //Otherwise, return true.
      if ((empty_fields == "") && (errors == "")) 
      {
        return true;
      }
      
      msg = "_____________________________________________________________________\n\n";
      if (empty_count + number_count == 1)
      {
        msg += "The form was not submitted because of the following error.\n";
        msg += "Please correct this error and re-submit.\n";
      }
      else
      {
        msg += "The form was not submitted because of the following errors.\n";
        msg += "Please correct these errors and re-submit.\n";
      }
      msg += "_____________________________________________________________________\n\n";
      
      if (empty_fields != "")
      {
        if (empty_count == 1)
        {
          msg += " - The following required field is empty or needs to be selected: " + empty_fields + "\n";
        }
        else
        {
          msg += " - The following required fields are empty or need to be selected: " + empty_fields + "\n";
        }
        if (errors != "") msg += "\n";
      }
      
      msg += errors; //It doesn't matter if errors is empty or not, just add it
      alert(msg);
      return false;
    }
