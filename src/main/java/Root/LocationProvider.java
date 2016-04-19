package Root;
/*
import org.mozilla.xpcom.IAppFileLocProvider;

import java.io.File;

public class LocationProvider implements IAppFileLocProvider
{

    private final File libXULPath;
    int counter = 0;

    public LocationProvider(File grePath) {
        this.libXULPath = grePath;
    }

    public File getFile(String aProp, boolean[] aPersistent) {
        File file = null;
        if (aProp.equals("GreD") || aProp.equals("GreComsD")) {
            file = libXULPath;
            if (aProp.equals("GreComsD")) {
                file = new File(file, "components");
            }
        }
        else if (aProp.equals("MozBinD") ||
                aProp.equals("CurProcD") ||
                aProp.equals("ComsD") ||
                aProp.equals("ProfD"))
        {
            file = libXULPath;
            if (aProp.equals("ComsD")) {
                file = new File(file, "components");
            }
        }
        return file;
    }

    public File[] getFiles(String aProp) {
        File[] files = null;
        if (aProp.equals("APluginsDL")) {
            files = new File[1];
            files[0] = new File(libXULPath, "plugins");
        }
        return files;
    }

}
*/