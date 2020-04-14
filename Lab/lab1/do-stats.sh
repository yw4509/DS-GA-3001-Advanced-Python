# Calculate stats for data files.
#!/usr/bin/env bash

for datafile in "$@"
do
    echo $datafile
    bash goostats $datafile stats-$datafile
done
