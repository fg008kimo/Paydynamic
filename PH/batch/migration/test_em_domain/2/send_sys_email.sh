#!/bin/sh
FROM_EMAIL="no-reply@corp.newco.local"

${EMAIL_TEMPLATE}/mailheader.sh |cat - $1 | sendmail -t -f${FROM_EMAIL}
