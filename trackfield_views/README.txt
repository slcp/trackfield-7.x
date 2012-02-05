This module exposes Trackfield data to views. 

Currntly it only exposes each settype (eg. latitude, longitude, altitude) as raw data. Each settype is available 
as a field in views, they are all linked to the node table as a base. 

Because Trackfield stores its data for each settype on a separate row in the database I have had to JOIN 
to the trackfield_datasets table using an alias for each settype, this has the potential for a large number 
of joins and when combined in a view with non-Trackfield data will have an increasingly detrimental effect 
on performance. 

I intend to expose the data in more meaningful ways as more pseudo-fields, for example as a linestring 
(currently a proof of concept in trackfield_wkt). 

These further efforts will also emulate Trackfield Stats functionality using the data in the view though I
have currently do not how I will accomplish this. 

In it's current state none of the data that is exposed is likely to be displayed but is potentially useful
when using graphing display plugins for views. I have not looked into this myself, as in in what format they
want the data. Manipulating the data by hooking into the view should pretty basic now that the raw data can be
made available should it need to be formatted differently.
