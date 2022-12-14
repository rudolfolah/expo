// Copyright 2017-present 650 Industries. All rights reserved.

typedef NS_OPTIONS(NSUInteger, ABI47_0_0EXAVAudioSessionMode)
{
  // These are enumerated in ascending order of priority.
  // The ABI47_0_0EXAVAudioSessionMode of the current experience (managed by ABI47_0_0EXAV) should be
  // the maximum of the ABI47_0_0EXAVAudioSessionModes required by each of the live ABI47_0_0EXAVObjects.
  ABI47_0_0EXAVAudioSessionModeInactive    = 0,
  ABI47_0_0EXAVAudioSessionModeActiveMuted = 1,
  ABI47_0_0EXAVAudioSessionModeActive      = 2
};

@protocol ABI47_0_0EXAVObject <NSObject> // For ABI47_0_0EXAVPlayerData and ABI47_0_0EXVideoView to interact with the Audio Session properly

- (void)pauseImmediately;

- (ABI47_0_0EXAVAudioSessionMode)getAudioSessionModeRequired; // TODO (clarity): is needsAudioSession a better name?

- (void)appDidForeground;

- (void)appDidBackgroundStayActive:(BOOL)stayActive;

- (void)handleAudioSessionInterruption:(NSNotification*)notification;

- (void)handleMediaServicesReset:(void (^)(void))finishCallback;

@end
