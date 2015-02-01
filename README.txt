

        JW PLAYER CDN - README
______________________________________________________________________________

NAME:       JW Player CDN
AUTHORS:    Brady Owens <info@fastglass.net>
______________________________________________________________________________


DESCRIPTION

This module creates an AWS Cloudfront CDN optimized JW Player 6 for Drupal 
content and supports videos that are made of multiple chapters but does 
not use playlists.

Cloudfront CDN Caveats

The requirement to play a video of multiple chapters often defaults to using 
the playlist functionality within JW Player. The requirement for this module 
was also protected content as the videos being played must be purchased - this 
means signed URLs. The bad news: AWS Cloudfront Signed URLs breaks XML playlists 
and after working on that for almost two weeks - even with JW Player 
Support - it cannot be fixed. The problem is the format of the URLs as it 
invalidates XML due to characters in the string.

This is why the approach taken by this module to play multiple chapters was 
taken.

INSTALLATION

To be written if this gets promoted to full project status.

EMBEDDED PLAYER

This module supports embedding the video player anywhere in Drupal using the
token system. You are free to choose whatever method that you would like to 
display the token.

If you want a quick and easy way to put it into content. You can download the
module Token Filter https://www.drupal.org/project/token_filter
____________________________________________________________________________
http://www.fastglass.net
