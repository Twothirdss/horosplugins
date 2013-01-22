//
//  PLDocumentView.h
//  PrintingLayout
//
//  Created by Benoit Deville on 19.11.12.
//
//

#import <Cocoa/Cocoa.h>
#import <OsiriXAPI/DCMView.h>
#import "PLLayoutView.h"
#import "PLUtils.h"

@interface PLDocumentView : NSView
{
    BOOL        isDraggingDestination;
    BOOL        fullWidth;
    
    CGFloat     sideMargin;
    CGFloat     topMargin;
    CGFloat     bottomMargin;
    
    paperSize   pageFormat;
    CGFloat     pageWidth;      // keep or not?
    CGFloat     pageHeight;     // keep or not?
//    scrollType  scrollingMode;  // to delete
    
    int         currentPageIndex;
}

@property BOOL fullWidth, isDraggingDestination;
@property CGFloat topMargin, bottomMargin, sideMargin;
@property (nonatomic, setter = setPageFormat:) paperSize pageFormat;
//@property scrollType scrollingMode;
@property int currentPageIndex;

- (void)resizePLDocumentView;
- (void)newPage;
- (void)removeCurrentPage;
- (void)insertPageAtIndex:(NSUInteger)index;
- (void)goToPage:(NSUInteger)pageNumber;
- (void)saveDocumentViewToPDF;
- (IBAction)insertImage:(id)sender;
- (IBAction)insertSerie:(id)sender;
- (void)insertImage:(DCMView*)dcm atIndex:(short)imgIndex toPage:(int)pageIndex inView:(NSUInteger)viewIndex;

@end