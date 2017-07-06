import sys
import operator
import requests
import json
import twitter
from watson_developer_cloud import PersonalityInsightsV2 as PersonalityInsights

# I used this tutorial https://www.codecademy.com/learn/ibm-watson and made some changes

def analyze(handle):

	# Opening keys.json that contains keys, keys.json is ignored.
	# Format of keys.json:
	"""
	{
  	  "twitter_consumer_key": "",
  	  "twitter_consumer_secret": "",
  	  "twitter_access_token": "",
  	  "twitter_access_secret": "",
  	  "pi_username": "",
  	  "pi_password": ""
	}
	"""
	with open('keys.json') as data_file:    
		data = json.load(data_file)

	# Change these to your respective Twitter App settings
	# Reading info from JSON
	twitter_consumer_key = data["twitter_consumer_key"]
	twitter_consumer_secret = data["twitter_consumer_secret"]
	twitter_access_token = data["twitter_access_token"]
	twitter_access_secret = data["twitter_access_secret"]
 	# Init Twitter Api
	twitter_api = twitter.Api(consumer_key=twitter_consumer_key, 
                          	  consumer_secret=twitter_consumer_secret, 
                          	  access_token_key=twitter_access_token, 
                          	  access_token_secret=twitter_access_secret)

	statuses = twitter_api.GetUserTimeline(screen_name=handle, 
										   count=200,
										   include_rts=False)

	text = ""

	for status in statuses:
		if (status.lang =='en'): #English tweets
  			text += status.text.encode('utf-8')
   			# print status.text.encode('utf-8')

	# End of Data Retrieval
	# Turns Twitter -> text

	# Watson PersonalityInsights, 
	# https://console.bluemix.net/dashboard/apps/?env_id=ibm:yp:us-south
	# Free Trial Account, might expire

	# Reading info from JSON
	pi_username = data["pi_username"]
	pi_password = data["pi_password"]

	# Init PersonalityInsights Api
	personality_insights = PersonalityInsights(username=pi_username, 
                                               password=pi_password)
	pi_result = personality_insights.profile(text)
	return pi_result

def flatten(orig): # JSON to Dictionary
	data = {}
	for c in orig['tree']['children']:
  		if 'children' in c:
			for c2 in c['children']:
      				if 'children' in c2:
        				for c3 in c2['children']:
          					if 'children' in c3:
            						for c4 in c3['children']:
              							if (c4['category'] == 'personality'):
               								data[c4['id']] = c4['percentage']
             								if 'children' not in c3:
             									if (c3['category'] == 'personality'):
                    									data[c3['id']] = c3['percentage']
	return data

def compare(dict1, dict2):
	compared_data = {}
	for keys in dict1:
  		if dict1[keys] != dict2[keys]:
    			compared_data[keys]=abs(dict1[keys] - dict2[keys])
	return compared_data


# Choose two Twitter handles
# Change to "@HANDLE"
user_handle =	"@atswolf"
celebrity_handle = "@realDonaldTrump"

user_result = analyze(user_handle)
celebrity_result = analyze(celebrity_handle)


user = flatten(user_result)
celebrity = flatten(celebrity_result)
compared_results= compare(user, celebrity)
sorted_result = sorted(compared_results.items(), key=operator.itemgetter(1))



for keys, value in sorted_result[:]:
	print("\n")
	print(keys)
	print("User:"),
	print(user[keys])
	print("Celebrity:"),
	print(celebrity[keys])
	print("Compared:"),
	print(compared_results[keys])

