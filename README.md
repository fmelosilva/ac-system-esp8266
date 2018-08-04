# AC System ESP8266

A flexible system to monitor and control an airconditioner. The monitoring has some backup rules.

## Usage
You can deploy some rules on system in runtime. The rules should be described in json format as shown bellow.

To build and upload the filesystem, run the commands bellow

```console
$ platformio run --target buildfs
$ platformio run --target uploadfs
```


### Some examples of rules:
```json
{
    "backup_rules":{
        "pulser": {
            "onEvent1": "action 1",
            "onEvent2": ["action 2", "action 3"]
        }
    }
}
```


| Entity        | Events              | 
| ------------- |:-------------------:| 
| Pulser        | On N pulses ocurred | 

### Available resources for monitoring:
* Pulse counter
