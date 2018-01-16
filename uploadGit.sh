#! /bin/bash

echo "Adding all files and folder to git!"
git add *
echo "Committing files all the files with the with the actual time"
now=`date`
git commit -m "$now"
git push