//
//  RoltoPrint.h
//  RoltoPrint
//
//  Copyright: (C) 2013 KING JIM CO.,LTD.
//

#import <Foundation/Foundation.h>

enum _RoltoPrintResult
{
    RoltoPrintResultSuccess,
    RoltoPrintResultUserCancel,
    RoltoPrintResultCommunicationError,
    RoltoPrintResultPaperOutError,
    RoltoPrintResultOverheatError,
    RoltoPrintResultCoverOpenError,
    RoltoPrintResultPrinterBusyError,
    RoltoPrintResultUnexpectedError,
};
typedef NSInteger RoltoPrintResult;

enum _RoltoPrinterStatus
{
    RoltoPrinterStatusIdle,
    RoltoPrinterStatusPrinting,
    RoltoPrinterStatusWritingFirmware,
    RoltoPrinterStatusCoveropen,
    RoltoPrinterStatusPaperOut,
    RoltoPrinterStatusOverheated,
};
typedef NSInteger RoltoPrinterStatus;


// performPrintImage params (NSDictionary)
extern NSString * const RoltoPrintParameterBlockSize;                // Float 0.0 - 1.0
extern NSString * const RoltoPrintParameterBinarizationOffset;       // Float 0.0 - 1.0
extern NSString * const RoltoPrintParameterErrorDiffusion;           // BOOL NO : Adaptive Threshold / YES : Error Diffusion


// API
// print functions.
@interface RoltoPrint: NSObject

@property (readonly, nonatomic) NSString *modelIdentifier;
@property (readonly, nonatomic) NSString *printerName;

- (void)performPrintImage:(UIImage *)image params:(NSDictionary *)params completion:(void (^)(RoltoPrintResult result))handler;
- (void)performPrintImagePaths:(NSArray *)paths params:(NSDictionary *)params completion:(void (^)(RoltoPrintResult result))handler;
- (void)cancelPrint;

// printer status function
- (void)requestPrinterStatus:(void (^)(BOOL result, RoltoPrinterStatus status))completion;
@end


// printer discovery
@interface RoltoPrintDiscover : NSObject
- (void)searchPrintersWithCallback:(void (^)(RoltoPrint *print))callback
                         comletion:(void (^)())completion
                          duration:(NSInteger)duration;
@end
