/*==============================================================================
 Copyright (c) 2012-2013 Qualcomm Connected Experiences, Inc.
 All Rights Reserved.
 ==============================================================================*/


#import <UIKit/UIKit.h>

#import <QCAR/UIGLViewProtocol.h>
#import <QCAR/TrackableResult.h>
#import <QCAR/Vectors.h>

#import "Texture.h"
#import "SampleApplicationSession.h"

// structure to point to an object to be drawn
@interface Object3D : NSObject {
    unsigned int numVertices;
    const float *vertices;
    const float *normals;
    const float *texCoords;
    
    unsigned int numIndices;
    const unsigned short *indices;
    
    Texture *texture;
}
@property (nonatomic) unsigned int numVertices;
@property (nonatomic) const float *vertices;
@property (nonatomic) const float *normals;
@property (nonatomic) const float *texCoords;

@property (nonatomic) unsigned int numIndices;
@property (nonatomic) const unsigned short *indices;

@property (nonatomic, assign) Texture *texture;

@end


#define NUM_AUGMENTATION_TEXTURES 1


// EAGLView is a subclass of UIView and conforms to the informal protocol
// UIGLViewProtocol
@interface CloudRecoEAGLView : UIView <UIGLViewProtocol> {
@private
    // OpenGL ES context
    EAGLContext *context;
    
    // The OpenGL ES names for the framebuffer and renderbuffers used to render
    // to this view
    GLuint defaultFramebuffer;
    GLuint colorRenderbuffer;
    GLuint depthRenderbuffer;
    
    // Shader handles
    GLuint shaderProgramID;
    GLint vertexHandle;
    GLint normalHandle;
    GLint textureCoordHandle;
    GLint mvpMatrixHandle;
    GLint texSampler2DHandle;
    
    // Texture used when rendering augmentation
    Texture* augmentationTexture[NUM_AUGMENTATION_TEXTURES];

    BOOL offTargetTrackingEnabled;
    
    SampleApplicationSession * vapp;
}


- (id)initWithFrame:(CGRect)frame appSession:(SampleApplicationSession *) app;
- (void)finishOpenGLESCommands;
- (void)freeOpenGLESResources;

@end
