#include "tesseract/baseapi.h"
#include "leptonica/allheaders.h"

#define TESSDATA "/Users/chenquanzhao/Workspace/tessdata"

int main() {
    char *outText;

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with Simplified-Chinese
    if (api->Init(TESSDATA, "chi_sim")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }

    // Open input image with leptonica library
    Pix *image = pixRead("/Users/chenquanzhao/Downloads/test.png");
    api->SetImage(image);
    // Get OCR result
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText);

    // Destroy used object and release memory
    api->End();
    delete api;
    delete [] outText;
    pixDestroy(&image);

    return 0;
}