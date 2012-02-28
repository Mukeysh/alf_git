Form Columns allows a developer to define which of 3 regions they want a top level field element for their form
to reside in. They may choose from Main, Right, and Footer. 

Developers may build Form Columns directly into their forms by setting the #columns attribute on
the form itself, and then the #region attribute on any top level elements they wish to position.
Any element without a #region defined will be placed into the Main region by default. Setting a 
#region of 'none' will take the element out of the columns completely.

Developers may add Form Columns functionality to an existing form by implementing hook_formcolumns.
Hook_formcolumns takes the form's #parameter value as its argument, and outputs an array of relevant 
field information. Used information includes 'region', 'weight', 'hidden', and 'collapsed'.

Form Columns is based on Node Form Columns.
