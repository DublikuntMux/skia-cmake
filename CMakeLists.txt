cmake_minimum_required(VERSION 3.25.0)
project(skia LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(SKIA_SHARED "Build shared Skia" OFF)
option(SKIA_STATIC "Build static Skia" ON)
option(SKIA_PNG "Build Skia with png support" OFF)
option(SKIA_WEBP "Build Skia with webp support" OFF)
option(SKIA_PDF "Build Skia with PDF support" OFF)
# option(SKIA_XML "Build Skia with xml support" OFF)
option(SKIA_GLFW "Build Skia with glfw support" OFF)

if(SKIA_STATIC AND SKIA_SHARED)
  message(ERROR "You cna only use one of SKIA_STATIC, SKIA_STATIC")
elseif(SKIA_STATIC)
  set(SKIA_SHARED OFF)
elseif(SKIA_SHARED)
  set(SKIA_STATIC OFF)
endif()

set(skia_sources
    src/base/SkArenaAlloc.cpp
    src/base/SkBase64.cpp
    src/base/SkBezierCurves.cpp
    src/base/SkBlockAllocator.cpp
    src/base/SkBuffer.cpp
    src/base/SkContainers.cpp
    src/base/SkCubics.cpp
    src/base/SkDebug.cpp
    src/base/SkDeque.cpp
    src/base/SkFloatingPoint.cpp
    src/base/SkHalf.cpp
    src/base/SkMalloc.cpp
    src/base/SkMathPriv.cpp
    src/base/SkQuads.cpp
    src/base/SkSafeMath.cpp
    src/base/SkSemaphore.cpp
    src/base/SkSharedMutex.cpp
    src/base/SkSpinlock.cpp
    src/base/SkTDArray.cpp
    src/base/SkTSearch.cpp
    src/base/SkThreadID.cpp
    src/base/SkTime.cpp
    src/base/SkUTF.cpp
    src/base/SkUtils.cpp

    src/codec/SkBmpBaseCodec.cpp
    src/codec/SkBmpCodec.cpp
    src/codec/SkBmpMaskCodec.cpp
    src/codec/SkBmpRLECodec.cpp
    src/codec/SkBmpStandardCodec.cpp
    src/codec/SkCodec.cpp
    src/codec/SkCodecImageGenerator.cpp
    src/codec/SkColorPalette.cpp
    src/codec/SkEncodedInfo.cpp
    src/codec/SkExif.cpp
    src/codec/SkHeifCodec.cpp
    src/codec/SkIcoCodec.cpp
    src/codec/SkImageGenerator_FromEncoded.cpp
    src/codec/SkMaskSwizzler.cpp
    src/codec/SkMasks.cpp
    src/codec/SkParseEncodedOrigin.cpp
    src/codec/SkPixmapUtils.cpp
    src/codec/SkSampledCodec.cpp
    src/codec/SkSampler.cpp
    src/codec/SkSwizzler.cpp
    src/codec/SkTiffUtility.cpp
    src/codec/SkWbmpCodec.cpp
    src/codec/SkXmp.cpp

    src/core/SkAAClip.cpp
    src/core/SkATrace.cpp
    src/core/SkAlphaRuns.cpp
    src/core/SkAnalyticEdge.cpp
    src/core/SkAnnotation.cpp
    src/core/SkAutoPixmapStorage.cpp
    src/core/SkBBHFactory.cpp
    src/core/SkBigPicture.cpp
    src/core/SkBitmap.cpp
    src/core/SkBitmapCache.cpp
    src/core/SkBitmapDevice.cpp
    src/core/SkBitmapProcState.cpp
    src/core/SkBitmapProcState_matrixProcs.cpp
    src/core/SkBitmapProcState_opts.cpp
    src/core/SkBitmapProcState_opts_hsw.cpp
    src/core/SkBitmapProcState_opts_ssse3.cpp
    src/core/SkBlendMode.cpp
    src/core/SkBlendModeBlender.cpp
    src/core/SkBlitMask_opts.cpp
    src/core/SkBlitMask_opts_ssse3.cpp
    src/core/SkBlitRow_D32.cpp
    src/core/SkBlitRow_opts.cpp
    src/core/SkBlitRow_opts_hsw.cpp
    src/core/SkBlitter.cpp
    src/core/SkBlitter_A8.cpp
    src/core/SkBlitter_ARGB32.cpp
    src/core/SkBlitter_Sprite.cpp
    src/core/SkBlurMask.cpp
    src/core/SkBlurMaskFilterImpl.cpp
    src/core/SkCachedData.cpp
    src/core/SkCanvas.cpp
    src/core/SkCanvasPriv.cpp
    src/core/SkCanvas_Raster.cpp
    src/core/SkCapabilities.cpp
    src/core/SkChecksum.cpp
    src/core/SkClipStack.cpp
    src/core/SkClipStackDevice.cpp
    src/core/SkCpu.cpp
    src/core/SkColor.cpp
    src/core/SkColorFilter.cpp
    src/core/SkColorSpace.cpp
    src/core/SkColorSpaceXformSteps.cpp
    src/core/SkColorTable.cpp
    src/core/SkCompressedDataUtils.cpp
    src/core/SkContourMeasure.cpp
    src/core/SkConvertPixels.cpp
    src/core/SkCubicClipper.cpp
    src/core/SkCubicMap.cpp
    src/core/SkData.cpp
    src/core/SkDataTable.cpp
    src/core/SkDescriptor.cpp
    src/core/SkDevice.cpp
    src/core/SkDistanceFieldGen.cpp
    src/core/SkDocument.cpp
    src/core/SkDraw.cpp
    src/core/SkDrawBase.cpp
    src/core/SkDrawLooper.cpp
    src/core/SkDrawShadowInfo.cpp
    src/core/SkDraw_atlas.cpp
    src/core/SkDraw_text.cpp
    src/core/SkDraw_vertices.cpp
    src/core/SkDrawable.cpp
    src/core/SkEdge.cpp
    src/core/SkEdgeBuilder.cpp
    src/core/SkEdgeClipper.cpp
    src/core/SkExecutor.cpp
    src/core/SkFlattenable.cpp
    src/core/SkFont.cpp
    src/core/SkFontDescriptor.cpp
    src/core/SkFontMetricsPriv.cpp
    src/core/SkFontMgr.cpp
    src/core/SkFontStream.cpp
    src/core/SkFont_serial.cpp
    src/core/SkGaussFilter.cpp
    src/core/SkGeometry.cpp
    src/core/SkGlobalInitialization_core.cpp
    src/core/SkGlyph.cpp
    src/core/SkGlyphRunPainter.cpp
    src/core/SkGraphics.cpp
    src/core/SkIDChangeListener.cpp
    src/core/SkImageFilter.cpp
    src/core/SkImageFilterCache.cpp
    src/core/SkImageFilterTypes.cpp
    src/core/SkImageGenerator.cpp
    src/core/SkImageInfo.cpp
    src/core/SkLatticeIter.cpp
    src/core/SkLineClipper.cpp
    src/core/SkLocalMatrixImageFilter.cpp
    src/core/SkM44.cpp
    src/core/SkMD5.cpp
    src/core/SkMallocPixelRef.cpp
    src/core/SkMask.cpp
    src/core/SkMaskBlurFilter.cpp
    src/core/SkMaskCache.cpp
    src/core/SkMaskFilter.cpp
    src/core/SkMaskGamma.cpp
    src/core/SkMatrix.cpp
    src/core/SkMatrixInvert.cpp
    src/core/SkMemset_opts.cpp
    src/core/SkMemset_opts_avx.cpp
    src/core/SkMemset_opts_erms.cpp
    src/core/SkMesh.cpp
    src/core/SkMipmap.cpp
    src/core/SkMipmapAccessor.cpp
    src/core/SkMipmapBuilder.cpp
    src/core/SkMipmapDrawDownSampler.cpp
    src/core/SkMipmapHQDownSampler.cpp
    src/core/SkOpts.cpp
    src/core/SkOverdrawCanvas.cpp
    src/core/SkPaint.cpp
    src/core/SkPaintPriv.cpp
    src/core/SkPath.cpp
    src/core/SkPathBuilder.cpp
    src/core/SkPathEffect.cpp
    src/core/SkPathMeasure.cpp
    src/core/SkPathRef.cpp
    src/core/SkPathUtils.cpp
    src/core/SkPath_serial.cpp
    src/core/SkPicture.cpp
    src/core/SkPictureData.cpp
    src/core/SkPictureFlat.cpp
    src/core/SkPicturePlayback.cpp
    src/core/SkPictureRecord.cpp
    src/core/SkPictureRecorder.cpp
    src/core/SkPixelRef.cpp
    src/core/SkPixmap.cpp
    src/core/SkPixmapDraw.cpp
    src/core/SkPoint.cpp
    src/core/SkPoint3.cpp
    src/core/SkPtrRecorder.cpp
    src/core/SkQuadClipper.cpp
    src/core/SkRRect.cpp
    src/core/SkRSXform.cpp
    src/core/SkRTree.cpp
    src/core/SkRasterClip.cpp
    src/core/SkRasterPipeline.cpp
    src/core/SkRasterPipelineBlitter.cpp
    src/core/SkReadBuffer.cpp
    src/core/SkReadPixelsRec.cpp
    src/core/SkRecord.cpp
    src/core/SkRecordDraw.cpp
    src/core/SkRecordOpts.cpp
    src/core/SkRecordedDrawable.cpp
    src/core/SkRecorder.cpp
    src/core/SkRecords.cpp
    src/core/SkRect.cpp
    src/core/SkRegion.cpp
    src/core/SkRegion_path.cpp
    src/core/SkResourceCache.cpp
    src/core/SkRuntimeBlender.cpp
    src/core/SkRuntimeEffect.cpp
    src/core/SkSLTypeShared.cpp
    src/core/SkScalar.cpp
    src/core/SkScalerContext.cpp
    src/core/SkScan.cpp
    src/core/SkScan_AAAPath.cpp
    src/core/SkScan_AntiPath.cpp
    src/core/SkScan_Antihair.cpp
    src/core/SkScan_Hairline.cpp
    src/core/SkScan_Path.cpp
    src/core/SkScan_SAAPath.cpp
    src/core/SkSpecialImage.cpp
    src/core/SkSpriteBlitter_ARGB32.cpp
    src/core/SkStream.cpp
    src/core/SkStrike.cpp
    src/core/SkStrikeCache.cpp
    src/core/SkStrikeSpec.cpp
    src/core/SkString.cpp
    src/core/SkStringUtils.cpp
    src/core/SkStroke.cpp
    src/core/SkStrokeRec.cpp
    src/core/SkStrokerPriv.cpp
    src/core/SkSwizzle.cpp
    src/core/SkSwizzler_opts.cpp
    src/core/SkSwizzler_opts_hsw.cpp
    src/core/SkSwizzler_opts_ssse3.cpp
    src/core/SkTaskGroup.cpp
    src/core/SkTextBlob.cpp
    src/core/SkTextBlobTrace.cpp
    src/core/SkTypeface.cpp
    src/core/SkTypefaceCache.cpp
    src/core/SkTypeface_remote.cpp
    src/core/SkUnPreMultiply.cpp
    src/core/SkVertState.cpp
    src/core/SkVertices.cpp
    src/core/SkWriteBuffer.cpp
    src/core/SkWritePixelsRec.cpp
    src/core/SkWriter32.cpp
    src/core/SkYUVAInfo.cpp
    src/core/SkYUVAPixmaps.cpp
    src/core/SkYUVMath.cpp
    src/core/SkYUVPlanesCache.cpp
    
    src/effects/Sk1DPathEffect.cpp
    src/effects/Sk2DPathEffect.cpp
    src/effects/SkBlenders.cpp
    src/effects/SkColorMatrix.cpp
    src/effects/SkColorMatrixFilter.cpp
    src/effects/SkCornerPathEffect.cpp
    src/effects/SkDashPathEffect.cpp
    src/effects/SkDiscretePathEffect.cpp
    src/effects/SkEmbossMask.cpp
    src/effects/SkEmbossMaskFilter.cpp
    src/effects/SkHighContrastFilter.cpp
    src/effects/SkLayerDrawLooper.cpp
    src/effects/SkShaderMaskFilterImpl.cpp
    src/effects/SkTableMaskFilter.cpp
    src/effects/SkTrimPathEffect.cpp
    src/effects/colorfilters/SkBlendModeColorFilter.cpp
    src/effects/colorfilters/SkColorFilterBase.cpp
    src/effects/colorfilters/SkColorSpaceXformColorFilter.cpp
    src/effects/colorfilters/SkComposeColorFilter.cpp
    src/effects/colorfilters/SkGaussianColorFilter.cpp
    src/effects/colorfilters/SkMatrixColorFilter.cpp
    src/effects/colorfilters/SkRuntimeColorFilter.cpp
    src/effects/colorfilters/SkTableColorFilter.cpp
    src/effects/colorfilters/SkWorkingFormatColorFilter.cpp
    src/effects/imagefilters/SkBlendImageFilter.cpp
    src/effects/imagefilters/SkBlurImageFilter.cpp
    src/effects/imagefilters/SkColorFilterImageFilter.cpp
    src/effects/imagefilters/SkComposeImageFilter.cpp
    src/effects/imagefilters/SkCropImageFilter.cpp
    src/effects/imagefilters/SkDisplacementMapImageFilter.cpp
    src/effects/imagefilters/SkDropShadowImageFilter.cpp
    src/effects/imagefilters/SkImageImageFilter.cpp
    src/effects/imagefilters/SkLightingImageFilter.cpp
    src/effects/imagefilters/SkMagnifierImageFilter.cpp
    src/effects/imagefilters/SkMatrixConvolutionImageFilter.cpp
    src/effects/imagefilters/SkMatrixTransformImageFilter.cpp
    src/effects/imagefilters/SkMergeImageFilter.cpp
    src/effects/imagefilters/SkMorphologyImageFilter.cpp
    src/effects/imagefilters/SkPictureImageFilter.cpp
    src/effects/imagefilters/SkRuntimeImageFilter.cpp
    src/effects/imagefilters/SkShaderImageFilter.cpp

    src/encode/SkEncoder.cpp
    src/encode/SkICC.cpp
    src/encode/SkJpegEncoder_none.cpp

    src/fonts/SkFontMgr_indirect.cpp
    src/fonts/SkRemotableFontMgr.cpp

    src/gpu/ganesh/ClipStack.cpp
    src/gpu/ganesh/Device.cpp
    src/gpu/ganesh/Device_drawTexture.cpp
    src/gpu/ganesh/GrAHardwareBufferImageGenerator.cpp
    src/gpu/ganesh/GrAHardwareBufferUtils.cpp
    src/gpu/ganesh/GrAttachment.cpp
    src/gpu/ganesh/GrAuditTrail.cpp
    src/gpu/ganesh/GrBackendSemaphore.cpp
    src/gpu/ganesh/GrBackendSurface.cpp
    src/gpu/ganesh/GrBackendTextureImageGenerator.cpp
    src/gpu/ganesh/GrBackendUtils.cpp
    src/gpu/ganesh/GrBlurUtils.cpp
    src/gpu/ganesh/GrBufferAllocPool.cpp
    src/gpu/ganesh/GrBufferTransferRenderTask.cpp
    src/gpu/ganesh/GrBufferUpdateRenderTask.cpp
    src/gpu/ganesh/GrCanvas.cpp
    src/gpu/ganesh/GrCaps.cpp
    src/gpu/ganesh/GrClientMappedBufferManager.cpp
    src/gpu/ganesh/GrColorInfo.cpp
    src/gpu/ganesh/GrColorSpaceXform.cpp
    src/gpu/ganesh/GrContextThreadSafeProxy.cpp
    src/gpu/ganesh/GrContext_Base.cpp
    src/gpu/ganesh/GrCopyRenderTask.cpp
    src/gpu/ganesh/GrDDLContext.cpp
    src/gpu/ganesh/GrDDLTask.cpp
    src/gpu/ganesh/GrDataUtils.cpp
    src/gpu/ganesh/GrDefaultGeoProcFactory.cpp
    src/gpu/ganesh/GrDeferredDisplayList.cpp
    src/gpu/ganesh/GrDeferredDisplayListRecorder.cpp
    src/gpu/ganesh/GrDirectContext.cpp
    src/gpu/ganesh/GrDirectContextPriv.cpp
    src/gpu/ganesh/GrDistanceFieldGenFromVector.cpp
    src/gpu/ganesh/GrDrawOpAtlas.cpp
    src/gpu/ganesh/GrDrawOpTest.cpp
    src/gpu/ganesh/GrDrawingManager.cpp
    src/gpu/ganesh/GrDriverBugWorkarounds.cpp
    src/gpu/ganesh/GrDynamicAtlas.cpp
    src/gpu/ganesh/GrEagerVertexAllocator.cpp
    src/gpu/ganesh/GrFinishCallbacks.cpp
    src/gpu/ganesh/GrFixedClip.cpp
    src/gpu/ganesh/GrFragmentProcessor.cpp
    src/gpu/ganesh/GrFragmentProcessors.cpp
    src/gpu/ganesh/GrGeometryProcessor.cpp
    src/gpu/ganesh/GrGpu.cpp
    src/gpu/ganesh/GrGpuBuffer.cpp
    src/gpu/ganesh/GrGpuResource.cpp
    src/gpu/ganesh/GrImageContext.cpp
    src/gpu/ganesh/GrImageInfo.cpp
    src/gpu/ganesh/GrManagedResource.cpp
    src/gpu/ganesh/GrMemoryPool.cpp
    src/gpu/ganesh/GrMeshBuffers.cpp
    src/gpu/ganesh/GrMeshDrawTarget.cpp
    src/gpu/ganesh/GrOnFlushResourceProvider.cpp
    src/gpu/ganesh/GrOpFlushState.cpp
    src/gpu/ganesh/GrOpsRenderPass.cpp
    src/gpu/ganesh/GrPaint.cpp
    src/gpu/ganesh/GrPersistentCacheUtils.cpp
    src/gpu/ganesh/GrPipeline.cpp
    src/gpu/ganesh/GrProcessor.cpp
    src/gpu/ganesh/GrProcessorAnalysis.cpp
    src/gpu/ganesh/GrProcessorSet.cpp
    src/gpu/ganesh/GrProcessorUnitTest.cpp
    src/gpu/ganesh/GrProgramDesc.cpp
    src/gpu/ganesh/GrProgramInfo.cpp
    src/gpu/ganesh/GrPromiseImageTexture.cpp
    src/gpu/ganesh/GrProxyProvider.cpp
    src/gpu/ganesh/GrRecordingContext.cpp
    src/gpu/ganesh/GrRecordingContextPriv.cpp
    src/gpu/ganesh/GrRenderTarget.cpp
    src/gpu/ganesh/GrRenderTargetProxy.cpp
    src/gpu/ganesh/GrRenderTask.cpp
    src/gpu/ganesh/GrRenderTaskCluster.cpp
    src/gpu/ganesh/GrResourceAllocator.cpp
    src/gpu/ganesh/GrResourceCache.cpp
    src/gpu/ganesh/GrResourceProvider.cpp
    src/gpu/ganesh/GrRingBuffer.cpp
    src/gpu/ganesh/GrSPIRVUniformHandler.cpp
    src/gpu/ganesh/GrSPIRVVaryingHandler.cpp
    src/gpu/ganesh/GrSWMaskHelper.cpp
    src/gpu/ganesh/GrShaderCaps.cpp
    src/gpu/ganesh/GrShaderVar.cpp
    src/gpu/ganesh/GrStagingBufferManager.cpp
    src/gpu/ganesh/GrStencilSettings.cpp
    src/gpu/ganesh/GrStyle.cpp
    src/gpu/ganesh/GrSurface.cpp
    src/gpu/ganesh/GrSurfaceCharacterization.cpp
    src/gpu/ganesh/GrSurfaceProxy.cpp
    src/gpu/ganesh/GrSurfaceProxyView.cpp
    src/gpu/ganesh/GrTestUtils.cpp
    src/gpu/ganesh/GrTexture.cpp
    src/gpu/ganesh/GrTextureProxy.cpp
    src/gpu/ganesh/GrTextureRenderTargetProxy.cpp
    src/gpu/ganesh/GrTextureResolveRenderTask.cpp
    src/gpu/ganesh/GrThreadSafeCache.cpp
    src/gpu/ganesh/GrThreadSafePipelineBuilder.cpp
    src/gpu/ganesh/GrTransferFromRenderTask.cpp
    src/gpu/ganesh/GrUniformDataManager.cpp
    src/gpu/ganesh/GrUtil.cpp
    src/gpu/ganesh/GrVertexChunkArray.cpp
    src/gpu/ganesh/GrWaitRenderTask.cpp
    src/gpu/ganesh/GrWritePixelsRenderTask.cpp
    src/gpu/ganesh/GrXferProcessor.cpp
    src/gpu/ganesh/GrYUVABackendTextures.cpp
    src/gpu/ganesh/GrYUVATextureProxies.cpp
    src/gpu/ganesh/PathRenderer.cpp
    src/gpu/ganesh/PathRendererChain.cpp
    src/gpu/ganesh/SkGr.cpp
    src/gpu/ganesh/StencilMaskHelper.cpp
    src/gpu/ganesh/SurfaceContext.cpp
    src/gpu/ganesh/SurfaceDrawContext.cpp
    src/gpu/ganesh/SurfaceFillContext.cpp
    src/gpu/ganesh/effects/GrBezierEffect.cpp
    src/gpu/ganesh/effects/GrBicubicEffect.cpp
    src/gpu/ganesh/effects/GrBitmapTextGeoProc.cpp
    src/gpu/ganesh/effects/GrBlendFragmentProcessor.cpp
    src/gpu/ganesh/effects/GrColorTableEffect.cpp
    src/gpu/ganesh/effects/GrConvexPolyEffect.cpp
    src/gpu/ganesh/effects/GrCoverageSetOpXP.cpp
    src/gpu/ganesh/effects/GrCustomXfermode.cpp
    src/gpu/ganesh/effects/GrDisableColorXP.cpp
    src/gpu/ganesh/effects/GrDistanceFieldGeoProc.cpp
    src/gpu/ganesh/effects/GrMatrixEffect.cpp
    src/gpu/ganesh/effects/GrModulateAtlasCoverageEffect.cpp
    src/gpu/ganesh/effects/GrOvalEffect.cpp
    src/gpu/ganesh/effects/GrPerlinNoise2Effect.cpp
    src/gpu/ganesh/effects/GrPorterDuffXferProcessor.cpp
    src/gpu/ganesh/effects/GrRRectEffect.cpp
    src/gpu/ganesh/effects/GrShadowGeoProc.cpp
    src/gpu/ganesh/effects/GrSkSLFP.cpp
    src/gpu/ganesh/effects/GrTextureEffect.cpp
    src/gpu/ganesh/effects/GrYUVtoRGBEffect.cpp
    src/gpu/ganesh/geometry/GrAAConvexTessellator.cpp
    src/gpu/ganesh/geometry/GrAATriangulator.cpp
    src/gpu/ganesh/geometry/GrPathUtils.cpp
    src/gpu/ganesh/geometry/GrQuad.cpp
    src/gpu/ganesh/geometry/GrQuadUtils.cpp
    src/gpu/ganesh/geometry/GrShape.cpp
    src/gpu/ganesh/geometry/GrStyledShape.cpp
    src/gpu/ganesh/geometry/GrTriangulator.cpp
    src/gpu/ganesh/gl/AHardwareBufferGL.cpp
    src/gpu/ganesh/gl/GrGLAssembleGLESInterfaceAutogen.cpp
    src/gpu/ganesh/gl/GrGLAssembleGLInterfaceAutogen.cpp
    src/gpu/ganesh/gl/GrGLAssembleHelpers.cpp
    src/gpu/ganesh/gl/GrGLAssembleInterface.cpp
    src/gpu/ganesh/gl/GrGLAssembleWebGLInterfaceAutogen.cpp
    src/gpu/ganesh/gl/GrGLAttachment.cpp
    src/gpu/ganesh/gl/GrGLBackendSurface.cpp
    src/gpu/ganesh/gl/GrGLBuffer.cpp
    src/gpu/ganesh/gl/GrGLCaps.cpp
    src/gpu/ganesh/gl/GrGLContext.cpp
    src/gpu/ganesh/gl/GrGLDirectContext.cpp
    src/gpu/ganesh/gl/GrGLExtensions.cpp
    src/gpu/ganesh/gl/GrGLGLSL.cpp
    src/gpu/ganesh/gl/GrGLGpu.cpp
    src/gpu/ganesh/gl/GrGLGpuProgramCache.cpp
    src/gpu/ganesh/gl/GrGLInterfaceAutogen.cpp
    src/gpu/ganesh/gl/GrGLOpsRenderPass.cpp
    src/gpu/ganesh/gl/GrGLProgram.cpp
    src/gpu/ganesh/gl/GrGLProgramDataManager.cpp
    src/gpu/ganesh/gl/GrGLRenderTarget.cpp
    src/gpu/ganesh/gl/GrGLSemaphore.cpp
    src/gpu/ganesh/gl/GrGLTexture.cpp
    src/gpu/ganesh/gl/GrGLTextureRenderTarget.cpp
    src/gpu/ganesh/gl/GrGLTypesPriv.cpp
    src/gpu/ganesh/gl/GrGLUniformHandler.cpp
    src/gpu/ganesh/gl/GrGLUtil.cpp
    src/gpu/ganesh/gl/GrGLVertexArray.cpp
    src/gpu/ganesh/gl/builders/GrGLProgramBuilder.cpp
    src/gpu/ganesh/gl/builders/GrGLShaderStringBuilder.cpp
    src/gpu/ganesh/glsl/GrGLSLBlend.cpp
    src/gpu/ganesh/glsl/GrGLSLFragmentShaderBuilder.cpp
    src/gpu/ganesh/glsl/GrGLSLProgramBuilder.cpp
    src/gpu/ganesh/glsl/GrGLSLProgramDataManager.cpp
    src/gpu/ganesh/glsl/GrGLSLShaderBuilder.cpp
    src/gpu/ganesh/glsl/GrGLSLUniformHandler.cpp
    src/gpu/ganesh/glsl/GrGLSLVarying.cpp
    src/gpu/ganesh/glsl/GrGLSLVertexGeoBuilder.cpp
    src/gpu/ganesh/gradients/GrGradientBitmapCache.cpp
    src/gpu/ganesh/gradients/GrGradientShader.cpp
    src/gpu/ganesh/image/GrImageUtils.cpp
    src/gpu/ganesh/image/GrTextureGenerator.cpp
    src/gpu/ganesh/image/SkImage_Ganesh.cpp
    src/gpu/ganesh/image/SkImage_GaneshBase.cpp
    src/gpu/ganesh/image/SkImage_GaneshFactories.cpp
    src/gpu/ganesh/image/SkImage_GaneshYUVA.cpp
    src/gpu/ganesh/image/SkImage_LazyTexture.cpp
    src/gpu/ganesh/image/SkImage_RasterPinnable.cpp
    src/gpu/ganesh/image/SkSpecialImage_Ganesh.cpp
    src/gpu/ganesh/mock/GrMockCaps.cpp
    src/gpu/ganesh/mock/GrMockGpu.cpp
    src/gpu/ganesh/mock/GrMockTypes.cpp
    src/gpu/ganesh/ops/AAConvexPathRenderer.cpp
    src/gpu/ganesh/ops/AAHairLinePathRenderer.cpp
    src/gpu/ganesh/ops/AALinearizingConvexPathRenderer.cpp
    src/gpu/ganesh/ops/AtlasInstancedHelper.cpp
    src/gpu/ganesh/ops/AtlasPathRenderer.cpp
    src/gpu/ganesh/ops/AtlasRenderTask.cpp
    src/gpu/ganesh/ops/AtlasTextOp.cpp
    src/gpu/ganesh/ops/ClearOp.cpp
    src/gpu/ganesh/ops/DashLinePathRenderer.cpp
    src/gpu/ganesh/ops/DashOp.cpp
    src/gpu/ganesh/ops/DefaultPathRenderer.cpp
    src/gpu/ganesh/ops/DrawAtlasOp.cpp
    src/gpu/ganesh/ops/DrawAtlasPathOp.cpp
    src/gpu/ganesh/ops/DrawMeshOp.cpp
    src/gpu/ganesh/ops/DrawableOp.cpp
    src/gpu/ganesh/ops/FillRRectOp.cpp
    src/gpu/ganesh/ops/FillRectOp.cpp
    src/gpu/ganesh/ops/GrMeshDrawOp.cpp
    src/gpu/ganesh/ops/GrOp.cpp
    src/gpu/ganesh/ops/GrOvalOpFactory.cpp
    src/gpu/ganesh/ops/GrSimpleMeshDrawOpHelper.cpp
    src/gpu/ganesh/ops/GrSimpleMeshDrawOpHelperWithStencil.cpp
    src/gpu/ganesh/ops/LatticeOp.cpp
    src/gpu/ganesh/ops/OpsTask.cpp
    src/gpu/ganesh/ops/PathInnerTriangulateOp.cpp
    src/gpu/ganesh/ops/PathStencilCoverOp.cpp
    src/gpu/ganesh/ops/PathTessellateOp.cpp
    src/gpu/ganesh/ops/QuadPerEdgeAA.cpp
    src/gpu/ganesh/ops/RegionOp.cpp
    src/gpu/ganesh/ops/ShadowRRectOp.cpp
    src/gpu/ganesh/ops/SmallPathAtlasMgr.cpp
    src/gpu/ganesh/ops/SmallPathRenderer.cpp
    src/gpu/ganesh/ops/SmallPathShapeData.cpp
    src/gpu/ganesh/ops/SoftwarePathRenderer.cpp
    src/gpu/ganesh/ops/StrokeRectOp.cpp
    src/gpu/ganesh/ops/StrokeTessellateOp.cpp
    src/gpu/ganesh/ops/TessellationPathRenderer.cpp
    src/gpu/ganesh/ops/TextureOp.cpp
    src/gpu/ganesh/ops/TriangulatingPathRenderer.cpp
    src/gpu/ganesh/surface/SkSurface_Ganesh.cpp
    src/gpu/ganesh/tessellate/GrPathTessellationShader.cpp
    src/gpu/ganesh/tessellate/GrStrokeTessellationShader.cpp
    src/gpu/ganesh/tessellate/GrTessellationShader.cpp
    src/gpu/ganesh/tessellate/PathTessellator.cpp
    src/gpu/ganesh/tessellate/StrokeTessellator.cpp
    src/gpu/ganesh/text/GrAtlasManager.cpp
  
    src/gpu/AtlasTypes.cpp
    src/gpu/Blend.cpp
    src/gpu/BlendFormula.cpp
    src/gpu/BlurUtils.cpp
    src/gpu/DitherUtils.cpp
    src/gpu/PipelineUtils.cpp
    src/gpu/RectanizerPow2.cpp
    src/gpu/RectanizerSkyline.cpp
    src/gpu/ResourceKey.cpp
    src/gpu/ShaderErrorHandler.cpp
    src/gpu/Swizzle.cpp
    src/gpu/TiledTextureUtils.cpp
    src/gpu/graphite/AtlasProvider.cpp
    src/gpu/graphite/BackendSemaphore.cpp
    src/gpu/graphite/BackendTexture.cpp
    src/gpu/graphite/Buffer.cpp
    src/gpu/graphite/BufferManager.cpp
    src/gpu/graphite/Caps.cpp
    src/gpu/graphite/ClearBuffersTask.cpp
    src/gpu/graphite/ClientMappedBufferManager.cpp
    src/gpu/graphite/ClipStack_graphite.cpp
    src/gpu/graphite/CommandBuffer.cpp
    src/gpu/graphite/ComputePipeline.cpp
    src/gpu/graphite/ComputeTask.cpp
    src/gpu/graphite/Context.cpp
    src/gpu/graphite/ContextUtils.cpp
    src/gpu/graphite/CopyTask.cpp
    src/gpu/graphite/Device.cpp
    src/gpu/graphite/DrawAtlas.cpp
    src/gpu/graphite/DrawContext.cpp
    src/gpu/graphite/DrawList.cpp
    src/gpu/graphite/DrawPass.cpp
    src/gpu/graphite/DrawWriter.cpp
    src/gpu/graphite/FactoryFunctions.cpp
    src/gpu/graphite/GlobalCache.cpp
    src/gpu/graphite/GpuWorkSubmission.cpp
    src/gpu/graphite/GraphicsPipeline.cpp
    src/gpu/graphite/GraphiteResourceKey.cpp
    src/gpu/graphite/ImageFactories.cpp
    src/gpu/graphite/Image_Base_Graphite.cpp
    src/gpu/graphite/Image_Graphite.cpp
    src/gpu/graphite/Image_YUVA_Graphite.cpp
    src/gpu/graphite/KeyContext.cpp
    src/gpu/graphite/KeyHelpers.cpp
    src/gpu/graphite/PaintParams.cpp
    src/gpu/graphite/PaintParamsKey.cpp
    src/gpu/graphite/PathAtlas.cpp
    src/gpu/graphite/PipelineData.cpp
    src/gpu/graphite/Precompile.cpp
    src/gpu/graphite/ProxyCache.cpp
    src/gpu/graphite/PublicPrecompile.cpp
    src/gpu/graphite/QueueManager.cpp
    src/gpu/graphite/RasterPathAtlas.cpp
    src/gpu/graphite/Recorder.cpp
    src/gpu/graphite/Recording.cpp
    src/gpu/graphite/RenderPassTask.cpp
    src/gpu/graphite/Renderer.cpp
    src/gpu/graphite/RendererProvider.cpp
    src/gpu/graphite/Resource.cpp
    src/gpu/graphite/ResourceCache.cpp
    src/gpu/graphite/ResourceProvider.cpp
    src/gpu/graphite/RuntimeEffectDictionary.cpp
    src/gpu/graphite/Sampler.cpp
    src/gpu/graphite/ShaderCodeDictionary.cpp
    src/gpu/graphite/SharedContext.cpp
    src/gpu/graphite/SpecialImage_Graphite.cpp
    src/gpu/graphite/Surface_Graphite.cpp
    src/gpu/graphite/SynchronizeToCpuTask.cpp
    src/gpu/graphite/Task.cpp
    src/gpu/graphite/TaskGraph.cpp
    src/gpu/graphite/Texture.cpp
    src/gpu/graphite/TextureInfo.cpp
    src/gpu/graphite/TextureProxy.cpp
    src/gpu/graphite/TextureUtils.cpp
    src/gpu/graphite/UniformManager.cpp
    src/gpu/graphite/UploadBufferManager.cpp
    src/gpu/graphite/UploadTask.cpp
    src/gpu/graphite/YUVABackendTextures.cpp
    src/gpu/graphite/YUVATextureProxies.cpp
    src/gpu/graphite/compute/ComputeStep.cpp
    src/gpu/graphite/compute/DispatchGroup.cpp
    src/gpu/graphite/geom/IntersectionTree.cpp
    src/gpu/graphite/geom/Shape.cpp
    src/gpu/graphite/geom/Transform.cpp
    src/gpu/graphite/render/AnalyticRRectRenderStep.cpp
    src/gpu/graphite/render/BitmapTextRenderStep.cpp
    src/gpu/graphite/render/CoverBoundsRenderStep.cpp
    src/gpu/graphite/render/CoverageMaskRenderStep.cpp
    src/gpu/graphite/render/GraphiteVertexFiller.cpp
    src/gpu/graphite/render/MiddleOutFanRenderStep.cpp
    src/gpu/graphite/render/PerEdgeAAQuadRenderStep.cpp
    src/gpu/graphite/render/SDFTextRenderStep.cpp
    src/gpu/graphite/render/TessellateCurvesRenderStep.cpp
    src/gpu/graphite/render/TessellateStrokesRenderStep.cpp
    src/gpu/graphite/render/TessellateWedgesRenderStep.cpp
    src/gpu/graphite/render/VerticesRenderStep.cpp
    src/gpu/graphite/text/TextAtlasManager.cpp
    src/gpu/tessellate/FixedCountBufferUtils.cpp
    src/gpu/tessellate/Tessellation.cpp

    src/image/SkImage.cpp
    src/image/SkImage_Base.cpp
    src/image/SkImage_Lazy.cpp
    src/image/SkImage_LazyFactories.cpp
    src/image/SkImage_Picture.cpp
    src/image/SkImage_Raster.cpp
    src/image/SkImage_RasterFactories.cpp
    src/image/SkPictureImageGenerator.cpp
    src/image/SkRescaleAndReadPixels.cpp
    src/image/SkSurface.cpp
    src/image/SkSurface_Base.cpp
    src/image/SkSurface_Null.cpp
    src/image/SkSurface_Raster.cpp
    src/image/SkTiledImageUtils.cpp

    src/lazy/SkDiscardableMemoryPool.cpp

    src/opts/SkOpts_hsw.cpp

    src/pathops/SkAddIntersections.cpp
    src/pathops/SkDConicLineIntersection.cpp
    src/pathops/SkDCubicLineIntersection.cpp
    src/pathops/SkDCubicToQuads.cpp
    src/pathops/SkDLineIntersection.cpp
    src/pathops/SkDQuadLineIntersection.cpp
    src/pathops/SkIntersections.cpp
    src/pathops/SkOpAngle.cpp
    src/pathops/SkOpBuilder.cpp
    src/pathops/SkOpCoincidence.cpp
    src/pathops/SkOpContour.cpp
    src/pathops/SkOpCubicHull.cpp
    src/pathops/SkOpEdgeBuilder.cpp
    src/pathops/SkOpSegment.cpp
    src/pathops/SkOpSpan.cpp
    src/pathops/SkPathOpsAsWinding.cpp
    src/pathops/SkPathOpsCommon.cpp
    src/pathops/SkPathOpsConic.cpp
    src/pathops/SkPathOpsCubic.cpp
    src/pathops/SkPathOpsCurve.cpp
    src/pathops/SkPathOpsDebug.cpp
    src/pathops/SkPathOpsLine.cpp
    src/pathops/SkPathOpsOp.cpp
    src/pathops/SkPathOpsQuad.cpp
    src/pathops/SkPathOpsRect.cpp
    src/pathops/SkPathOpsSimplify.cpp
    src/pathops/SkPathOpsTSect.cpp
    src/pathops/SkPathOpsTightBounds.cpp
    src/pathops/SkPathOpsTypes.cpp
    src/pathops/SkPathOpsWinding.cpp
    src/pathops/SkPathWriter.cpp
    src/pathops/SkReduceOrder.cpp

    src/ports/SkDiscardableMemory_none.cpp
    src/ports/SkFontHost_FreeType.cpp
    src/ports/SkFontHost_FreeType_common.cpp
    src/ports/SkFontHost_win.cpp
    src/ports/SkFontMgr_custom.cpp
    src/ports/SkFontMgr_custom_directory.cpp
    src/ports/SkFontMgr_custom_directory_factory.cpp
    src/ports/SkFontMgr_custom_embedded.cpp
    src/ports/SkFontMgr_custom_embedded_factory.cpp
    src/ports/SkFontMgr_custom_empty.cpp
    src/ports/SkFontMgr_custom_empty_factory.cpp
    src/ports/SkFontMgr_empty_factory.cpp
    src/ports/SkGlobalInitialization_default.cpp
    src/ports/SkImageGenerator_skia.cpp
    src/ports/SkMemory_malloc.cpp
    src/ports/SkOSFile_stdio.cpp

    src/sfnt/SkOTTable_name.cpp
    src/sfnt/SkOTUtils.cpp

    src/shaders/SkBitmapProcShader.cpp
    src/shaders/SkBlendShader.cpp
    src/shaders/SkColorFilterShader.cpp
    src/shaders/SkColorShader.cpp
    src/shaders/SkCoordClampShader.cpp
    src/shaders/SkEmptyShader.cpp
    src/shaders/SkGainmapShader.cpp
    src/shaders/SkImageShader.cpp
    src/shaders/SkLocalMatrixShader.cpp
    src/shaders/SkPerlinNoiseShaderImpl.cpp
    src/shaders/SkPictureShader.cpp
    src/shaders/SkRuntimeShader.cpp
    src/shaders/SkShader.cpp
    src/shaders/SkShaderBase.cpp
    src/shaders/SkTransformShader.cpp
    src/shaders/SkTriColorShader.cpp
    src/shaders/SkWorkingColorSpaceShader.cpp
    src/shaders/gradients/SkConicalGradient.cpp
    src/shaders/gradients/SkGradientBaseShader.cpp
    src/shaders/gradients/SkLinearGradient.cpp
    src/shaders/gradients/SkRadialGradient.cpp
    src/shaders/gradients/SkSweepGradient.cpp

    src/sksl/SkSLAnalysis.cpp
    src/sksl/SkSLBuiltinTypes.cpp
    src/sksl/SkSLCompiler.cpp
    src/sksl/SkSLConstantFolder.cpp
    src/sksl/SkSLContext.cpp
    src/sksl/SkSLErrorReporter.cpp
    src/sksl/SkSLInliner.cpp
    src/sksl/SkSLIntrinsicList.cpp
    src/sksl/SkSLLexer.cpp
    src/sksl/SkSLMangler.cpp
    src/sksl/SkSLModuleLoader.cpp
    src/sksl/SkSLOperator.cpp
    src/sksl/SkSLOutputStream.cpp
    src/sksl/SkSLParser.cpp
    src/sksl/SkSLPool.cpp
    src/sksl/SkSLPosition.cpp
    src/sksl/SkSLSampleUsage.cpp
    src/sksl/SkSLString.cpp
    src/sksl/SkSLThreadContext.cpp
    src/sksl/SkSLUtil.cpp
    src/sksl/analysis/SkSLCanExitWithoutReturningValue.cpp
    src/sksl/analysis/SkSLCheckProgramStructure.cpp
    src/sksl/analysis/SkSLFinalizationChecks.cpp
    src/sksl/analysis/SkSLGetLoopControlFlowInfo.cpp
    src/sksl/analysis/SkSLGetLoopUnrollInfo.cpp
    src/sksl/analysis/SkSLGetReturnComplexity.cpp
    src/sksl/analysis/SkSLHasSideEffects.cpp
    src/sksl/analysis/SkSLIsConstantExpression.cpp
    src/sksl/analysis/SkSLIsDynamicallyUniformExpression.cpp
    src/sksl/analysis/SkSLIsSameExpressionTree.cpp
    src/sksl/analysis/SkSLIsTrivialExpression.cpp
    src/sksl/analysis/SkSLProgramUsage.cpp
    src/sksl/analysis/SkSLReturnsInputAlpha.cpp
    src/sksl/analysis/SkSLSwitchCaseContainsExit.cpp
    src/sksl/analysis/SkSLSymbolTableStackBuilder.cpp
    src/sksl/codegen/SkSLGLSLCodeGenerator.cpp
    src/sksl/codegen/SkSLMetalCodeGenerator.cpp
    src/sksl/codegen/SkSLPipelineStageCodeGenerator.cpp
    src/sksl/codegen/SkSLRasterPipelineBuilder.cpp
    src/sksl/codegen/SkSLRasterPipelineCodeGenerator.cpp
    src/sksl/codegen/SkSLSPIRVCodeGenerator.cpp
    src/sksl/codegen/SkSLSPIRVtoHLSL.cpp
    src/sksl/codegen/SkSLWGSLCodeGenerator.cpp
    src/sksl/ir/SkSLBinaryExpression.cpp
    src/sksl/ir/SkSLBlock.cpp
    src/sksl/ir/SkSLChildCall.cpp
    src/sksl/ir/SkSLConstructor.cpp
    src/sksl/ir/SkSLConstructorArray.cpp
    src/sksl/ir/SkSLConstructorArrayCast.cpp
    src/sksl/ir/SkSLConstructorCompound.cpp
    src/sksl/ir/SkSLConstructorCompoundCast.cpp
    src/sksl/ir/SkSLConstructorDiagonalMatrix.cpp
    src/sksl/ir/SkSLConstructorMatrixResize.cpp
    src/sksl/ir/SkSLConstructorScalarCast.cpp
    src/sksl/ir/SkSLConstructorSplat.cpp
    src/sksl/ir/SkSLConstructorStruct.cpp
    src/sksl/ir/SkSLDiscardStatement.cpp
    src/sksl/ir/SkSLDoStatement.cpp
    src/sksl/ir/SkSLExpression.cpp
    src/sksl/ir/SkSLExpressionStatement.cpp
    src/sksl/ir/SkSLExtension.cpp
    src/sksl/ir/SkSLFieldAccess.cpp
    src/sksl/ir/SkSLForStatement.cpp
    src/sksl/ir/SkSLFunctionCall.cpp
    src/sksl/ir/SkSLFunctionDeclaration.cpp
    src/sksl/ir/SkSLFunctionDefinition.cpp
    src/sksl/ir/SkSLIfStatement.cpp
    src/sksl/ir/SkSLIndexExpression.cpp
    src/sksl/ir/SkSLInterfaceBlock.cpp
    src/sksl/ir/SkSLLayout.cpp
    src/sksl/ir/SkSLLiteral.cpp
    src/sksl/ir/SkSLModifierFlags.cpp
    src/sksl/ir/SkSLModifiersDeclaration.cpp
    src/sksl/ir/SkSLPostfixExpression.cpp
    src/sksl/ir/SkSLPrefixExpression.cpp
    src/sksl/ir/SkSLProgram.cpp
    src/sksl/ir/SkSLSetting.cpp
    src/sksl/ir/SkSLStructDefinition.cpp
    src/sksl/ir/SkSLSwitchCase.cpp
    src/sksl/ir/SkSLSwitchStatement.cpp
    src/sksl/ir/SkSLSwizzle.cpp
    src/sksl/ir/SkSLSymbolTable.cpp
    src/sksl/ir/SkSLTernaryExpression.cpp
    src/sksl/ir/SkSLType.cpp
    src/sksl/ir/SkSLTypeReference.cpp
    src/sksl/ir/SkSLVarDeclarations.cpp
    src/sksl/ir/SkSLVariable.cpp
    src/sksl/ir/SkSLVariableReference.cpp
    src/sksl/lex/NFA.cpp
    src/sksl/lex/RegexNode.cpp
    src/sksl/lex/RegexParser.cpp
    src/sksl/lex/TransitionTable.cpp
    src/sksl/tracing/SkSLDebugTracePlayer.cpp
    src/sksl/tracing/SkSLDebugTracePriv.cpp
    src/sksl/tracing/SkSLTraceHook.cpp
    src/sksl/transform/SkSLAddConstToVarModifiers.cpp
    src/sksl/transform/SkSLEliminateDeadFunctions.cpp
    src/sksl/transform/SkSLEliminateDeadGlobalVariables.cpp
    src/sksl/transform/SkSLEliminateDeadLocalVariables.cpp
    src/sksl/transform/SkSLEliminateEmptyStatements.cpp
    src/sksl/transform/SkSLEliminateUnreachableCode.cpp
    src/sksl/transform/SkSLFindAndDeclareBuiltinFunctions.cpp
    src/sksl/transform/SkSLFindAndDeclareBuiltinVariables.cpp
    src/sksl/transform/SkSLHoistSwitchVarDeclarationsAtTopLevel.cpp
    src/sksl/transform/SkSLRenamePrivateSymbols.cpp
    src/sksl/transform/SkSLReplaceConstVarsWithLiterals.cpp
    src/sksl/transform/SkSLRewriteIndexedSwizzle.cpp

    src/svg/SkSVGCanvas.cpp
    src/svg/SkSVGDevice.cpp

    src/utils/SkAnimCodecPlayer.cpp
    src/utils/SkCamera.cpp
    src/utils/SkCanvasStack.cpp
    src/utils/SkCanvasStateUtils.cpp
    src/utils/SkCharToGlyphCache.cpp
    src/utils/SkClipStackUtils.cpp
    src/utils/SkCustomTypeface.cpp
    src/utils/SkDashPath.cpp
    src/utils/SkEventTracer.cpp
    src/utils/SkFloatToDecimal.cpp
    src/utils/SkJSON.cpp
    src/utils/SkJSONWriter.cpp
    src/utils/SkMatrix22.cpp
    src/utils/SkMultiPictureDocument.cpp
    src/utils/SkNWayCanvas.cpp
    src/utils/SkNullCanvas.cpp
    src/utils/SkOSPath.cpp
    src/utils/SkOrderedFontMgr.cpp
    src/utils/SkPaintFilterCanvas.cpp
    src/utils/SkParse.cpp
    src/utils/SkParseColor.cpp
    src/utils/SkParsePath.cpp
    src/utils/SkPatchUtils.cpp
    src/utils/SkPolyUtils.cpp
    src/utils/SkShaderUtils.cpp
    src/utils/SkShadowTessellator.cpp
    src/utils/SkShadowUtils.cpp
    src/utils/SkTestCanvas.cpp
    src/utils/SkTextUtils.cpp

    src/text/GlyphRun.cpp
    src/text/SlugFromBuffer.cpp
    src/text/StrikeForGPU.cpp
    src/text/gpu/DistanceFieldAdjustTable.cpp
    src/text/gpu/GlyphVector.cpp
    src/text/gpu/SDFMaskFilter.cpp
    src/text/gpu/SDFTControl.cpp
    src/text/gpu/SkChromeRemoteGlyphCache.cpp
    src/text/gpu/Slug.cpp
    src/text/gpu/SlugImpl.cpp
    src/text/gpu/StrikeCache.cpp
    src/text/gpu/SubRunAllocator.cpp
    src/text/gpu/SubRunContainer.cpp
    src/text/gpu/TextBlob.cpp
    src/text/gpu/TextBlobRedrawCoordinator.cpp
    src/text/gpu/VertexFiller.cpp

    third_party/etc1/etc1.cpp
    third_party/icu/SkLoadICU.cpp

    modules/skcms/skcms.cc
)

if(SKIA_PDF)
  list(APPEND skia_sources
    src/pdf/SkClusterator.cpp
    src/pdf/SkDeflate.cpp
    src/pdf/SkDocument_PDF_None.cpp
    src/pdf/SkJpegInfo_none.cpp
    src/pdf/SkKeyedImage.cpp
    src/pdf/SkPDFBitmap.cpp
    src/pdf/SkPDFDevice.cpp
    src/pdf/SkPDFDocument.cpp
    src/pdf/SkPDFFont.cpp
    src/pdf/SkPDFFormXObject.cpp
    src/pdf/SkPDFGradientShader.cpp
    src/pdf/SkPDFGraphicStackState.cpp
    src/pdf/SkPDFGraphicState.cpp
    src/pdf/SkPDFMakeCIDGlyphWidthsArray.cpp
    src/pdf/SkPDFMakeToUnicodeCmap.cpp
    src/pdf/SkPDFMetadata.cpp
    src/pdf/SkPDFResourceDict.cpp
    src/pdf/SkPDFShader.cpp
    src/pdf/SkPDFSubsetFont.cpp
    src/pdf/SkPDFTag.cpp
    src/pdf/SkPDFType1Font.cpp
    src/pdf/SkPDFTypes.cpp
    src/pdf/SkPDFUtils.cpp
  )
endif()

if(SKIA_PNG)
  add_definitions(-DSK_HAS_PNG_LIBRARY)
  
  list(APPEND skia_sources
    src/codec/SkPngCodec.cpp
    src/encode/SkPngEncoderImpl.cpp
  )
else()
  list(APPEND skia_sources
    src/encode/SkPngEncoder_none.cpp
  )
endif()

if(SKIA_WEBP)
  list(APPEND skia_sources
    src/encode/SkWebpEncoderImpl.cpp
  )
else()
  list(APPEND skia_sources
    src/encode/SkWebpEncoder_none.cpp
  )
endif()

if(SKIA_XML)
  list(APPEND skia_sources
    src/xml/SkDOM.cpp
    src/xml/SkXMLParser.cpp
    src/xml/SkXMLWriter.cpp
  )
endif()

if(SKIA_GLFW)
  list(APPEND skia_sources
    src/gpu/ganesh/gl/glfw/GrGLMakeNativeInterface_glfw.cpp
  )
endif()

if(WIN32)
  list(APPEND skia_sources
              src/ports/SkDebug_win.cpp
              src/ports/SkFontHost_win.cpp
              src/ports/SkFontMgr_win_dw.cpp
              src/ports/SkFontMgr_win_dw_factory.cpp
              src/ports/SkOSFile_win.cpp
              src/ports/SkOSLibrary_win.cpp
              src/ports/SkRemotableFontMgr_win_dw.cpp
              src/ports/SkScalerContext_win_dw.cpp
              src/ports/SkTypeface_win_dw.cpp
              src/utils/win/SkAutoCoInitialize.cpp
              src/utils/win/SkDWrite.cpp
              src/utils/win/SkDWriteFontFileStream.cpp
              src/utils/win/SkDWriteGeometrySink.cpp
              src/utils/win/SkHRESULT.cpp
              src/utils/win/SkIStream.cpp
              src/utils/win/SkWGL_win.cpp
              src/gpu/ganesh/gl/win/GrGLMakeNativeInterface_win.cpp
              )
endif()
if(UNIX AND NOT MINGW)
  list(APPEND skia_sources
              src/ports/SkDebug_stdio.cpp
              src/ports/SkOSFile_posix.cpp
              src/ports/SkOSLibrary_posix.cpp
             )
  if(APPLE)
    list(APPEND skia_sources
                src/ports/SkFontMgr_mac_ct.cpp
                src/ports/SkFontMgr_mac_ct_factory.cpp
                src/ports/SkImageEncoder_CG.cpp
                src/ports/SkImageGeneratorCG.cpp
                src/ports/SkScalerContext_mac_ct.cpp
                src/ports/SkTypeface_mac_ct.cpp
                src/utils/mac/SkCreateCGImageRef.cpp
                src/utils/mac/SkCTFontSmoothBehavior.cpp
                src/gpu/ganesh/gl/mac/GrGLMakeNativeInterface_mac.cpp
               )
  elseif(LINUX)
    list(APPEND skia_sources
                src/ports/SkFontConfigInterface_direct_factory.cpp
                src/ports/SkFontConfigInterface_direct.cpp
                src/ports/SkFontConfigInterface.cpp
                src/ports/SkFontHost_FreeType_common.cpp
                src/ports/SkFontHost_FreeType.cpp
                src/ports/SkFontMgr_fontconfig_factory.cpp
                src/ports/SkFontMgr_fontconfig.cpp
                src/ports/SkFontMgr_FontConfigInterface_factory.cpp
                src/ports/SkFontMgr_FontConfigInterface.cpp
                src/gpu/ganesh/gl/egl/GrGLMakeEGLInterface.cpp
                src/gpu/ganesh/gl/egl/GrGLMakeNativeInterface_egl.cpp
              )
  endif()
endif()

if(ARM)
  list(APPEND skia_sources
              src/opts/SkBitmapProcState_arm_neon.cpp
              src/opts/SkBitmapProcState_matrixProcs_neon.cpp
              src/opts/SkBitmapProcState_opts_arm.cpp
              src/opts/SkBlitMask_opts_arm.cpp
              src/opts/SkBlitMask_opts_arm_neon.cpp
              src/opts/SkBlitRow_opts_arm.cpp
              src/opts/SkBlitRow_opts_arm_neon.cpp
              )
endif()

file(GLOB_RECURSE skia_headers
                  src/*.h
                  include/*.h)
if(SKIA_SHARED)
  add_library(skia SHARED
                   ${skia_sources} ${skia_headers}
                   )
  target_compile_definitions(skia PRIVATE -DSKIA_DLL)
elseif(SKIA_STATIC)
  add_library(skia STATIC
                   ${skia_sources} ${skia_headers}
                   )
endif()

target_compile_definitions(skia PRIVATE SKIA_IMPLEMENTATION=1)
target_compile_definitions(skia PUBLIC SK_RELEASE)
target_compile_definitions(skia PUBLIC SK_GANESH)

include(FetchContent)
include(ExternalProject)

FetchContent_Declare(
  freetype
  GIT_REPOSITORY https://github.com/freetype/freetype.git
  GIT_TAG VER-2-13-2
)

set(FT_DISABLE_BROTLI ON CACHE BOOL "" FORCE)
set(FT_DISABLE_BZIP2 ON CACHE BOOL "" FORCE)
set(FT_DISABLE_PNG ON CACHE BOOL "" FORCE)
set(FT_DISABLE_ZLIB ON CACHE BOOL "" FORCE)
set(FT_DISABLE_HARFBUZZ ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(freetype)

if(SKIA_WEBP)
  FetchContent_Declare(
    libwebp
    GIT_REPOSITORY https://github.com/webmproject/libwebp.git
    GIT_TAG main
  )
  set(WEBP_BUILD_ANIM_UTILS OFF CACHE BOOL "" FORCE)
  set(WEBP_BUILD_CWEBP OFF CACHE BOOL "" FORCE)
  set(WEBP_BUILD_DWEBP OFF CACHE BOOL "" FORCE)
  set(WEBP_BUILD_GIF2WEBP OFF CACHE BOOL "" FORCE)
  set(WEBP_BUILD_IMG2WEBP OFF CACHE BOOL "" FORCE)
  set(WEBP_BUILD_VWEBP OFF CACHE BOOL "" FORCE)
  set(WEBP_BUILD_WEBPINFO OFF CACHE BOOL "" FORCE)
  set(WEBP_BUILD_LIBWEBPMUX OFF CACHE BOOL "" FORCE)
  set(WEBP_BUILD_WEBPMUX  OFF CACHE BOOL "" FORCE)
  set(WEBP_BUILD_EXTRAS OFF CACHE BOOL "" FORCE)

  FetchContent_MakeAvailable(libwebp)

  target_link_libraries(skia PRIVATE webp webpdemux)
endif()

if(SKIA_PNG OR SKIA_PDF)
  FetchContent_Declare(
    zlib
    GIT_REPOSITORY https://github.com/daktronics/zlib.git
    GIT_TAG develop
  )
  
  set(ZLIB_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

  FetchContent_MakeAvailable(zlib)
  target_link_libraries(skia PRIVATE zlibstatic)
  target_include_directories(skia PRIVATE 
    ${zlib_SOURCE_DIR}
    ${zlib_BINARY_DIR}
  )
endif()

if(SKIA_PNG)
  FetchContent_Declare(
    libpng
    GIT_REPOSITORY https://github.com/glennrp/libpng.git
    GIT_TAG v1.6.40
  )

  set(PNG_SHARED OFF CACHE BOOL "" FORCE)
  set(PNG_TESTS OFF CACHE BOOL "" FORCE)
  set(PNG_TOOLS OFF CACHE BOOL "" FORCE)

  FetchContent_MakeAvailable(libpng)
  target_link_libraries(skia PRIVATE png_static)
  target_include_directories(skia PRIVATE 
    ${libpng_SOURCE_DIR}
    ${libpng_BINARY_DIR}
  )
endif()

if(SKIA_GLFW)
  FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.3.8
  )

  set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
  set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
  set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
  set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

  FetchContent_MakeAvailable(glfw)
  target_link_libraries(skia PRIVATE glfw)
endif()

if(SKIA_XML)
  FetchContent_Declare(
    expat
    GIT_REPOSITORY https://github.com/libexpat/libexpat.git
    GIT_TAG master
  )

  FetchContent_MakeAvailable(expat)
  target_link_libraries(skia PRIVATE expat)
  target_include_directories(skia PRIVATE 
    ${expat_SOURCE_DIR}/expat
  )
endif()

target_link_libraries(skia PRIVATE freetype)
target_include_directories(skia PRIVATE 
  ${freetype_SOURCE_DIR}/include
)

if(APPLE)
  target_link_libraries(skia PRIVATE "-framework CoreText"
                                     "-framework CoreGraphics"
                                     "-framework Foundation"
  )
endif()

target_include_directories(skia SYSTEM PUBLIC .)
