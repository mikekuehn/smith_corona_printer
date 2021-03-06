//
//  AppDelegate.h
//  BeanDemo
//
//  Created by Chris Gregg on 6/13/14.
//  Copyright (c) 2014 Chris Gregg. All rights reserved.
//
//  The LightBlue Bean can be found here:
//  http://punchthrough.com/bean/
//
//  The libBean SDK can be found here:
//  https://github.com/PunchThrough/Bean-iOS-OSX-SDK


#import <Cocoa/Cocoa.h>
#import "PTDBean.h"
#import "PTDBeanManager.h"
#import "PTDBeanRadioConfig.h"
#import "BEAN_Globals.h"
#import "ORSSerialPort.h"
#import "ORSSerialPortManager.h"

#define connectedCheck @"✅"
#define disconnectedX @"❌"

// define BEAN for lightblue Bean, and UNO for Arduino UNO
#define UNO

#define PORTPARTIAL @"wchusbserial"

#ifdef BEAN
@interface AppDelegate : NSObject <NSApplicationDelegate, PTDBeanManagerDelegate, PTDBeanDelegate, NSTableViewDataSource> {
        NSLock *threadLock;
}
#else
@interface AppDelegate : NSObject <NSApplicationDelegate, NSTableViewDataSource, ORSSerialPortDelegate> {
        NSLock *threadLock;
}
#endif

@property (assign) IBOutlet NSWindow *window;
@property (assign) IBOutlet NSWindow *scanSheet;
@property (retain) PTDBeanManager *beanManager;
@property (assign) IBOutlet NSTableView *scanTable;
@property (retain) NSMutableArray *beans; // the BLE devices we find
@property (retain) PTDBean *bean;
@property (weak) NSTimer *updateTimer;
@property (retain) IBOutlet NSProgressIndicator *connectionProgress;
@property (retain) IBOutlet NSTextField *connectedLabel;
@property int timeStep;
@property (assign) IBOutlet NSTextField *SRCLR;
@property (assign) IBOutlet NSTextField *G;
@property (assign) IBOutlet NSTextField *RCK;
@property (assign) IBOutlet NSTextField *SRCK;
@property (assign) IBOutlet NSTextField *SER_IN;
@property (assign) IBOutlet NSTextField *SHIFT;
@property (assign) IBOutlet NSTextField *LED;
@property (assign) IBOutlet NSTextView *textToSend;
@property (assign) IBOutlet NSTextField *beginRange;
@property (assign) IBOutlet NSTextField *endRange;
@property (nonatomic, strong) ORSSerialPortManager *serialPortManager;
@property (retain) ORSSerialPort *serialPort;
@property (nonatomic, retain) NSTimer *connectionTimer;

@property (nonatomic,retain) NSMutableArray* byteQueue;

- (void)openUNOport;
- (void) openScanSheet;
- (IBAction) closeScanSheet:(id)sender;
- (IBAction) cancelScanSheet:(id)sender;
- (IBAction) newConnectionMenu:(id)sender;
- (IBAction) disconnect:(id)sender;

- (IBAction) toggleSRCLR:(id)sender;
- (IBAction) toggleG:(id)sender;
- (IBAction) toggleRCK:(id)sender;
- (IBAction) toggleSRCK:(id)sender;
- (IBAction) toggleSER_IN:(id)sender;
- (IBAction) toggleSHIFT:(id)sender;
- (IBAction) toggleLED:(id)sender;
- (IBAction) shiftZero:(id) sender;
- (IBAction) shiftOne:(id) sender;
- (void) setAll;
- (IBAction) clearAll:(id)sender;
- (IBAction) sendKeystroke:(id)sender;
- (IBAction) test8:(id)sender;
- (IBAction) sendText:(id)sender;
- (IBAction) sendRange:(id)sender;
- (void) setBit:(int)bit;
- (void) addCharToSerialQueue:(char)oneChar;

- (void) addStringToSerialQueue:(NSString *)str;
- (void) sendSpecialCommand:(NSString *)str;
- (void) sendSerialByte;
- (NSString *)replaceForTypewriter:(NSString *)str;
- (void)updateAll;

@end
