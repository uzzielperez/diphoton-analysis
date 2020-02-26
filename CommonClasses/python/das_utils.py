import json
import subprocess

def get_number_of_events(dataset):
  """Get number of events for dataset from DAS"""
  query = "file dataset=" + dataset + " | sum(file.nevents)"

  cmd = "dasgoclient --format=json --query='" + query + "'"
  print "Executing: " + cmd
  data = subprocess.check_output(cmd, shell=True)

  if isinstance(data, basestring):
    dasjson = json.loads(data)
  else:
    dasjson = data
  status  = dasjson.get('status')
  sumevents = 0
  if  status == 'ok':
    data = dasjson.get('data')
    for idata in data:
      sumevents += idata.get('result')['value']
  return sumevents
