#!/bin/sh
FROM_EMAIL="no-reply@n-servicing.com"

${EMAIL_TEMPLATE}/mailheader.sh |cat - $1 | sendmail -t -f${FROM_EMAIL}
