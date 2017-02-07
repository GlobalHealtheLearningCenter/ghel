

TO ADD A NEW LOCATION,  Region or Subregion
============================================================
============================================================
1. Edit Field values via:  admin/config/people/accounts/fields  , and add your new field & value

TO ADD A NEW RELATIONSHIP RECORD for Location/Sub Region/Region
============================================================
============================================================
There is currently no administrative page to add this relationship so it must be done in the database.

1.  INSERT INTO ghel_location_lookup(region_key, sub_region_key, location_description, location_key) VALUES (number, number, 'string', number );
2.  (Optional)  Update data/ghel_location.csv with new values (should you ever want fresh install to include your new values).

