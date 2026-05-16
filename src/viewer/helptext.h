// helptext — loads localized strings from BW's LanguageR.dll / LanguageD.dll.
//
// The DLL is a standard Win32 PE-resource container; we LoadLibraryEx it
// as a datafile and read the RT_STRING resource bundles. The combined
// string table goes into a flat id -> text map that hosts can query.

#pragma once

#include <string>

namespace bw {
namespace helptext {

// Load strings from a .dll. Returns the number of strings discovered.
// Safe to call multiple times to merge entries from several files
// (e.g. LanguageR for resources and LanguageD for descriptions).
size_t LoadFromDLL(const std::string& dll_path);

// Look up the localized text for `id`. Returns empty string if unknown.
const char* Lookup(int32_t id);

// Total entries currently in the map.
size_t Count();

// Direct insert (used by sources other than DLLs, e.g. SAD audio bank
// names). First-write-wins so DLL-derived strings stay authoritative.
void Add(int32_t id, const std::string& text);

} // namespace helptext
} // namespace bw
