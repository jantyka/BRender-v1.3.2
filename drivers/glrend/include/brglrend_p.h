#ifndef _BRGLREND_P_H
#define _BRGLREND_P_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _NO_PROTOTYPES

/*
 * Main entry point for device.
 */
struct br_device *BR_EXPORT BrDrv1GLBegin(const char *arguments);

/*
 * Copy every flush of the 2D overlay into a hidden render target (NULL: off)
 */
void BR_EXPORT BrGLRendSetOverlayCapture(br_pixelmap *screen, br_pixelmap *target);

#endif /* _NO_PROTOTYPES */

#ifdef __cplusplus
};
#endif
#endif
