//
//  STButtonSensor.h
//  TISensorTag
//
//  Created by Andre Muis on 11/15/13.
//  Copyright (c) 2013 Andre Muis. All rights reserved.
//

#import <CoreBluetooth/CoreBluetooth.h>
#import <Foundation/Foundation.h>

#import "STSensor.h"

@protocol STSensorTagDelegate;

typedef NS_ENUM(NSUInteger, STButtonsPressed)
{
    STButtonsPressedUnknown,
    STButtonsPressedNone,
    STButtonsPressedRight,
    STButtonsPressedLeft,
    STButtonsPressedBoth
};

@interface STButtonSensor : STSensor

@property (readonly, strong, nonatomic) CBUUID *dataCharacteristicUUID;
@property (readwrite, strong, nonatomic) CBCharacteristic *dataCharacteristic;

@property (readonly, assign, nonatomic) BOOL configured;
@property (readwrite, assign, nonatomic) BOOL enabled;

- (id)initWithSensorTagDelegate: (id<STSensorTagDelegate>)sensorTagDelegate
            sensorTagPeripheral: (CBPeripheral *)sensorTagPeripheral;

- (void)sensorTagPeripheralDidUpdateValueForCharacteristic: (CBCharacteristic *)characteristic;

- (STButtonsPressed)buttonsPressedWithCharacteristicValue: (NSData *)characteristicValue;

@end
