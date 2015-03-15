

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

Frankfurt Region

Amazon has chosen to force version 4 signing of URLs for the Frankfurt region
S3 buckets with no backward compatibility. This is in contrast to every other 
region within the AWS ecosystem. This module does not support v4 signing because
there are some underlying issues with the signing and Frankfurt region that 
we cannot solve, see here: https://github.com/aws/aws-sdk-php/issues/483

Make sure your assets for videos are not in the Frankfurt S3 region!

INSTALLATION

To be written if this gets promoted to full project status.

THANKS AND ACKNOWLEDGEMENTS

A lot of the code here was borrowed from the JW Player for Drupal 7 Module. The
two modules share a lot of the same common functions.
https://www.drupal.org/project/jw_player
____________________________________________________________________________
http://www.fastglass.net
